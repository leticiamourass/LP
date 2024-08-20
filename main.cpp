#include <iostream>
#include <string>
#include <vector>
#include <random>

class Sapo {
private:
    std::string nome;
    int identificador;
    int distanciaPercorrida;
    int quantidadePulos;
    int provasDisputadas;
    int vitorias;
    int empates;
    int quantidadeTotalPulos;

public:
    static int distanciaTotalCorrida;

    Sapo(std::string nome, int identificador) 
        : nome(nome), identificador(identificador), distanciaPercorrida(0), quantidadePulos(0), 
          provasDisputadas(0), vitorias(0), empates(0), quantidadeTotalPulos(0) {}

    // getters...
    std::string getNome() const { return nome; }
    int getIdentificador() const { return identificador; }
    int getDistanciaPercorrida() const { return distanciaPercorrida; }
    int getQuantidadePulos() const { return quantidadePulos; }
    int getProvasDisputadas() const { return provasDisputadas; }
    int getVitorias() const { return vitorias; }
    int getEmpates() const { return empates; }
    int getQuantidadeTotalPulos() const { return quantidadeTotalPulos; }

    // método para pular
    void pular() {
        static std::random_device rd;
        static std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(1, 10);

        int distanciaPulo = dis(gen);
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

int Sapo::distanciaTotalCorrida = 100;

void realizarCorrida(std::vector<Sapo>& sapos) {
    bool corridaTerminada = false;
    std::vector<Sapo*> vencedores;

    while (!corridaTerminada) {
        for (Sapo& sapo : sapos) {
            sapo.pular();

            if (sapo.getDistanciaPercorrida() >= Sapo::distanciaTotalCorrida) {
                vencedores.push_back(&sapo);
                corridaTerminada = true;
            }
        }
    }

    // verifica se houve empate ou um único vencedor
    if (vencedores.size() == 1) {
        vencedores[0]->incrementarVitorias();
        std::cout << "O sapo " << vencedores[0]->getNome() << " venceu a corrida!" << std::endl;
    } else {
        std::cout << "A corrida terminou em empate entre os sapos: ";
        for (Sapo* sapo : vencedores) {
            sapo->incrementarEmpates();
            std::cout << sapo->getNome() << " ";
        }
        std::cout << std::endl;
    }

    // atualiza estatísticas e reseta corrida para todos os sapos
    for (Sapo& sapo : sapos) {
        sapo.incrementarProvas();
        sapo.resetarCorrida();
    }
}

int main() {
    std::vector<Sapo> sapos = { Sapo("CrazyFrog", 1), Sapo("Cururu", 2) };

    realizarCorrida(sapos);

    return 0;
}
