#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <chrono>
#include <thread>
#include <iomanip> 

class Sapo {
private:
    std::string nome;
    int identificador;
    double distanciaPercorrida;
    int quantidadePulos;
    int provasDisputadas;
    int vitorias;
    int empates;
    int quantidadeTotalPulos;

public:
    static double distanciaTotalCorrida;

    Sapo(std::string nome, int identificador) 
        : nome(nome), identificador(identificador), distanciaPercorrida(0), quantidadePulos(0), 
          provasDisputadas(0), vitorias(0), empates(0), quantidadeTotalPulos(0) {}

    // getters...
    std::string getNome() const { return nome; }
    int getIdentificador() const { return identificador; }
    double getDistanciaPercorrida() const { return distanciaPercorrida; }
    int getQuantidadePulos() const { return quantidadePulos; }
    int getProvasDisputadas() const { return provasDisputadas; }
    int getVitorias() const { return vitorias; }
    int getEmpates() const { return empates; }
    int getQuantidadeTotalPulos() const { return quantidadeTotalPulos; }

    // método para pular
    void pular() {
        static std::random_device rd;
        static std::mt19937 gen(rd());
        std::uniform_real_distribution<> dis(0.5, 2.0);  // Pulo entre 0.5 e 2.0 metros

        double distanciaPulo = dis(gen);
        distanciaPulo = std::round(distanciaPulo * 100.0) / 100.0;
        distanciaPercorrida += distanciaPulo;
        quantidadePulos++;
        quantidadeTotalPulos++;
    }

    // incrementar valores
    void incrementarProvas() { provasDisputadas++; }
    void incrementarVitorias() { vitorias++; }
    void incrementarEmpates() { empates++; }

    // reseta os dados para uma nova corrida
    void resetarCorrida() {
        distanciaPercorrida = 0;
        quantidadePulos = 0;
    }
};

double Sapo::distanciaTotalCorrida = 20.0;

void realizarCorrida(std::vector<Sapo>& sapos) {
    bool corridaTerminada = false;
    Sapo* vencedor = nullptr;

    while (!corridaTerminada) {
        for (Sapo& sapo : sapos) {
            sapo.pular();
            std::cout << "O sapo " << sapo.getNome() << " pulou! Distância percorrida: " 
                      << std::fixed << std::setprecision(2) << sapo.getDistanciaPercorrida() 
                      << " metros." << std::endl;

            if (sapo.getDistanciaPercorrida() >= Sapo::distanciaTotalCorrida) {
                vencedor = &sapo;
                corridaTerminada = true;
                break;
            }
        }
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    if (vencedor) {
        vencedor->incrementarVitorias();
        std::cout << "O sapo " << vencedor->getNome() << " venceu a corrida!" << std::endl;
    }

    // atualiza estatísticas e reseta corrida para todos os sapos
    for (Sapo& sapo : sapos) {
        sapo.incrementarProvas();
        sapo.resetarCorrida();
    }
}

int main() {
    int quantidadeSapos;
    std::cout << "Digite o número de sapos participantes: ";
    std::cin >> quantidadeSapos;
    std::cin.ignore(); // para limpar o buffer do teclado

    std::vector<Sapo> sapos;
    for (int i = 0; i < quantidadeSapos; ++i) {
        std::string nome;
        std::cout << "Digite o nome do sapo " << (i + 1) << ": ";
        std::getline(std::cin, nome);
        sapos.emplace_back(nome, i + 1);
    }

    while (true) {
        realizarCorrida(sapos);
        std::cout << "Pressione Enter para reiniciar a corrida...";
        std::cin.ignore();
    }

    return 0;
}

