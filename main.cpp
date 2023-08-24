#include <iostream>
#include <string>
#include <vector>

struct Item {
    std::string nome;
    std::string descricao;
    // Adicione os campos restantes do item aqui...
};

class RegistroDeItens {
private:
    std::vector<Item> itens;

public:
    void criarItem(const Item& novoItem) {
        itens.push_back(novoItem);
    }

    void listarItens() {
        for (const Item& item : itens) {
            std::cout << "Nome: " << item.nome << "\n";
            std::cout << "Descrição: " << item.descricao << "\n";
            // Liste os campos restantes do item aqui...
            std::cout << "-------------------------\n";
        }
    }

    void buscarItem(const std::string& nomeBusca) {
        for (const Item& item : itens) {
            if (item.nome == nomeBusca) {
                std::cout << "Item encontrado:\n";
                std::cout << "Nome: " << item.nome << "\n";
                std::cout << "Descrição: " << item.descricao << "\n";
                // Liste os campos restantes do item aqui...
                std::cout << "-------------------------\n";
                return;
            }
        }
        std::cout << "Item não encontrado.\n";
    }

    void editarItem(const std::string& nomeEdicao) {
        for (Item& item : itens) {
            if (item.nome == nomeEdicao) {
                std::cout << "Digite o novo nome: ";
                std::getline(std::cin, item.nome);
                std::cout << "Digite a nova descrição: ";
                std::getline(std::cin, item.descricao);
                // Atualize os campos restantes do item aqui...
                std::cout << "Item editado com sucesso.\n";
                return;
            }
        }
        std::cout << "Item não encontrado.\n";
    }

    void deletarItem(const std::string& nomeDelecao) {
        for (auto it = itens.begin(); it != itens.end(); ++it) {
            if (it->nome == nomeDelecao) {
                itens.erase(it);
                std::cout << "Item deletado com sucesso.\n";
                return;
            }
        }
        std::cout << "Item não encontrado.\n";
    }
};

int main() {
    RegistroDeItens registro;

    while (true) {
        std::cout << "1. Criar Item\n";
        std::cout << "2. Listar Itens\n";
        std::cout << "3. Buscar Item\n";
        std::cout << "4. Editar Item\n";
        std::cout << "5. Deletar Item\n";
        std::cout << "6. Sair\n";
        std::cout << "Escolha uma opção: ";

        int opcao;
        std::cin >> opcao;
        std::cin.ignore(); // Limpar o caractere de nova linha deixado pelo std::cin

        if (opcao == 1) {
            Item novoItem;
            std::cout << "Digite o nome do novo item: ";
            std::getline(std::cin, novoItem.nome);
            std::cout << "Digite a descrição do novo item: ";
            std::getline(std::cin, novoItem.descricao);
            registro.criarItem(novoItem);
        } else if (opcao == 2) {
            registro.listarItens();
        } else if (opcao == 3) {
            std::string nomeBusca;
            std::cout << "Digite o nome do item a ser buscado: ";
            std::getline(std::cin, nomeBusca);
            registro.buscarItem(nomeBusca);
        } else if (opcao == 4) {
            std::string nomeEdicao;
            std::cout << "Digite o nome do item a ser editado: ";
            std::getline(std::cin, nomeEdicao);
            registro.editarItem(nomeEdicao);
        } else if (opcao == 5) {
            std::string nomeDelecao;
            std::cout << "Digite o nome do item a ser deletado: ";
            std::getline(std::cin, nomeDelecao);
            registro.deletarItem(nomeDelecao);
        } else if (opcao == 6) {
            break;
        } else {
            std::cout << "Opção inválida. Escolha novamente.\n";
        }
    }

    return 0;
}
