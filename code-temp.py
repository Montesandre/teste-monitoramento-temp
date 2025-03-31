import csv
from datetime import datetime
import time
import random

class MonitoramentoTemperatura:
    def __init__(self):
        self.temperaturas = []
        self.alertas = 0
        self.limite_seguro = 80.0  # Limite de temperatura em °C
        self.arquivo_log = f"log_temperatura_{datetime.now().strftime('%Y%m%d_%H%M%S')}.csv"
        
        # Criando o arquivo CSV com cabeçalho
        with open(self.arquivo_log, mode='w', newline='') as file:
            writer = csv.writer(file)
            writer.writerow(['Timestamp', 'Temperatura (°C)', 'Status'])
    
    def ler_sensor(self):
        """Simula a leitura do sensor entre 60°C e 90°C"""
        return round(random.uniform(60, 90), 2)
    
    def verificar_temperatura(self, temp):
        """Verifica se a temperatura está dentro do limite seguro"""
        if temp > self.limite_seguro:
            self.alertas += 1
            print(f"🚨 ALERTA! Temperatura crítica: {temp}°C")
            return "CRÍTICO"
        elif temp > self.limite_seguro - 5:
            return "ATENÇÃO"
        else:
            return "NORMAL"
    
    def registrar_temperatura(self, temp, status):
        """Registra as leituras no arquivo CSV"""
        timestamp = datetime.now().strftime('%Y-%m-%d %H:%M:%S')
        self.temperaturas.append((timestamp, temp, status))
        
        with open(self.arquivo_log, mode='a', newline='') as file:
            writer = csv.writer(file)
            writer.writerow([timestamp, temp, status])
    
    def exibir_status(self, temp, status):
        """Exibe o status da temperatura no console"""
        print(f"[{datetime.now().strftime('%H:%M:%S')}] Temperatura: {temp:.1f}°C - {status}")
    
    def executar_monitoramento(self, duracao=30):
        """Executa a leitura e monitoramento da temperatura por um tempo determinado"""
        print(f"📡 Iniciando monitoramento (limite: {self.limite_seguro}°C)")
        print(f"📄 Log salvo em: {self.arquivo_log}\n")
        
        try:
            for _ in range(duracao):
                temperatura = self.ler_sensor()
                status = self.verificar_temperatura(temperatura)
                self.registrar_temperatura(temperatura, status)
                self.exibir_status(temperatura, status)
                time.sleep(1)
            
            print("\n✅ Monitoramento concluído!")
            print(f"⚠️ Total de alertas críticos: {self.alertas}")
        
        except KeyboardInterrupt:
            print("\n⏹️ Monitoramento interrompido pelo usuário.")
        except Exception as e:
            print(f"\n❌ Erro: {str(e)}")
        finally:
            print(f"📂 Dados salvos em: {self.arquivo_log}")

if __name__ == "__main__":
    monitor = MonitoramentoTemperatura()
    monitor.executar_monitoramento(duracao=60)  # Executa por 60 segundos
