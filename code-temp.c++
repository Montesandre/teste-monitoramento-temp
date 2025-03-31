#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <thread>
#include <chrono>

using namespace std;

class MonitoramentoTemperatura {
private:
    string arquivo_log;
    int alertas;
    const float limite_seguro = 80.0; // Temperatura máxima permitida

public:
    MonitoramentoTemperatura() {
        alertas = 0;
        time_t agora = time(0);
        char nome_arquivo[50];
        strftime(nome_arquivo, sizeof(nome_arquivo), "log_temperatura_%Y%m%d_%H%M%S.csv", localtime(&agora));
        arquivo_log = nome_arquivo;
        
        ofstream file(arquivo_log);
        file << "Timestamp,Temperatura (°C),Status" << endl;
        file.close();
    }
    
    float ler_sensor() {
        return 60 + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (90 - 60)));
    }
    
    string verificar_temperatura(float temp) {
        if (temp > limite_seguro) {
            alertas++;
            cout << "🚨 ALERTA! Temperatura crítica: " << temp << "°C" << endl;
            return "CRÍTICO";
        } else if (temp > limite_seguro - 5) {
            return "ATENÇÃO";
        } else {
            return "NORMAL";
        }
    }
    
    void registrar_temperatura(float temp, string status) {
        time_t agora = time(0);
        char timestamp[20];
        strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", localtime(&agora));
        
        ofstream file(arquivo_log, ios::app);
        file << timestamp << "," << temp << "," << status << endl;
        file.close();
    }
    
    void exibir_status(float temp, string status) {
        time_t agora = time(0);
        char timestamp[10];
        strftime(timestamp, sizeof(timestamp), "%H:%M:%S", localtime(&agora));
        
        cout << "[" << timestamp << "] Temperatura: " << temp << "°C - " << status << endl;
    }
    
    void executar_monitoramento(int duracao) {
        cout << "📡 Iniciando monitoramento (limite: " << limite_seguro << "°C)" << endl;
        cout << "📄 Log salvo em: " << arquivo_log << "\n" << endl;
        
        try {
            for (int i = 0; i < duracao; i++) {
                float temperatura = ler_sensor();
                string status = verificar_temperatura(temperatura);
                registrar_temperatura(temperatura, status);
                exibir_status(temperatura, status);
                this_thread::sleep_for(chrono::seconds(1));
            }
            
            cout << "\n✅ Monitoramento concluído!" << endl;
            cout << "⚠️ Total de alertas críticos: " << alertas << endl;
        } catch (exception& e) {
            cerr << "\n❌ Erro: " << e.what() << endl;
        }
    }
};

int main() {
    srand(time(0));
    MonitoramentoTemperatura monitor;
    monitor.executar_monitoramento(60); // Executa por 60 segundos
    return 0;
}
