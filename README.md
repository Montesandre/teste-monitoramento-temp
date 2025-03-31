# 🌡️ Sistema de Monitoramento de Temperatura Industrial

**Olá, pessoal sejam bem-vindo ao projeto de monitoramento de temperatura!** Este sistema foi desenvolvido como teste para simular o acompanhamento de condições térmicas em equipamentos industriais, com foco em prevenção de danos por superaquecimento.

## 📌 Funcionalidades Principais

- 🔥 **Leituras contínuas**: Simula leituras de temperatura a cada segundo
- 🚨 **Sistema de alertas**: Notifica quando a temperatura ultrapassa 80°C
- 📊 **Registro de dados**: Armazena todas as medições em arquivo CSV
- ⚙️ **Multiplataforma**: Versões disponíveis em Python e C++

## 🛠️ Tecnologias Utilizadas

| Componente | Descrição |
|------------|-----------|
| `code-temp.py` | Versão Python para prototipagem rápida |
| `code-temp.cpp` | Versão C++ para sistemas embarcados |
| CSV | Formato simples para registro dos dados |
| Simulação de sensor | Geração de valores aleatórios para testes |

## ⚡ Como Executar

### Pré-requisitos
- Python 3.x (para versão Python)
- Compilador C++ (para versão C++)

### Passo a Passo

1. Clone o repositório:
```bash
git clone https://github.com/Montesandre/teste-monitoramento-temp.git
cd teste-monitoramento-temp
```

2. **Para versão Python**:
```bash
python code-temp.py
```

3. **Para versão C++**:
```bash
g++ code-temp.cpp -o monitoramento
./monitoramento
```

## 📊 Saída do Sistema

O programa gera:
- Exibição em tempo real no console (com cores para diferentes níveis)
- Arquivo CSV com padrão: `temperature_log_AAAAMMDD_HHMMSS.csv`

Exemplo de saída:
```
[14:25:36] Temperatura: 72.3°C - NORMAL
[14:25:37] Temperatura: 85.1°C - ALERTA CRÍTICO!
```

## 🔍 Estrutura do Projeto

```
teste-monitoramento-temp/
├── code-temp.py        # Versão Python do monitoramento
├── code-temp.cpp       # Versão C++ para sistemas embarcados
└── README.md           # Documentação do projeto
```

## 📌 Observações Importantes

1. Este projeto foi desenvolvido **para fins de teste e aprendizado**
2. Os valores do sensor são simulados (aleatórios entre 60°C e 90°C)
3. Para uso em produção, será necessário:
   - Integrar com sensores reais
   - Ajustar limites de temperatura conforme especificação do equipamento
   - Implementar tratamento adicional de erros

## 🤝 Como Contribuir

Sugestões são bem-vindas! Você pode:
- Reportar issues
- Enviar pull requests
- Sugerir melhorias na documentação

## 💡 Próximos Passos (Roadmap)

- [ ] Adicionar interface gráfica simples
- [ ] Implementar cálculo de média móvel
- [ ] Adicionar suporte para múltiplos sensores
- [ ] Criar sistema de alertas por e-mail

---


