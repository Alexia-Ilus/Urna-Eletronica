#include <iostream>
#include <stack>
#include <list>
#include <queue>

using namespace std;



struct Candidato
{
    string numero;
    string nome;
    int votos = 0;
    string vice;
    string partido;
};
struct CandidatoV
{
    string numero;
    string nome;
    int votos = 0;
};


int main()
{
    stack <Candidato> listaP;
    queue <Candidato> votarP;
    queue <CandidatoV> votarV;
    stack <CandidatoV> listaV;
    queue <Candidato> auP;
    queue <CandidatoV> auV;
    Candidato aux;
    CandidatoV auxV;
    int nuloV = 0;
    int brancoV = 0;
    int nuloP = 0;
    int brancoP = 0;
    string voto;
    int i = 0;
    bool vere = false;
    bool resposta = false;
    string resp;
    bool votacaoV = false;
    bool votacaoP = false;
    bool votacao = false;
    list <Candidato> respP;
    list <CandidatoV> respV;
    list <CandidatoV> ::iterator it;
    bool prefe = false;
    Candidato venV;
    venV.votos = 0;
    Candidato venP;
    venP.votos = 0;

    cout << "Serao adicionado os candidatos para prefeito\n\n";

    while (i < 5 && !prefe)
    {
        cout << "Insira o nome do prefeito para eleicao\n";
        cin >> aux.nome;

        cout << "\nInsira o nome do vice-prefeito para eleicao\n";
        cin >> aux.vice;

        cout << "\nInsira o numero do prefeito para eleicao\n";
        cin >> aux.numero;

        if (aux.numero == "11")
        {
            aux.partido = "PP";
        }
        else if (aux.numero == "12")
        {
            aux.partido = "PDT";
        }
        else if (aux.numero == "13")
        {
            aux.partido = "PT";
        }
        else if (aux.numero == "14")
        {
            aux.partido = "PTB";
        }
        else if (aux.numero == "15")
        {
            aux.partido = "MDB";
        }
        else if (aux.numero == "17")
        {
            aux.partido = "PSL";
        }
        else if (aux.numero == "21")
        {
            aux.partido = "PCB";
        }
        else if (aux.numero == "22")
        {
            aux.partido = "PL";
        }
        else if (aux.numero == "30")
        {
            aux.partido = "NOVO";
        }
        else if (aux.numero == "40")
        {
            aux.partido = "PSB";
        }
        else if (aux.numero == "43")
        {
            aux.partido = "PV";
        }
        else if (aux.numero == "45")
        {
            aux.partido = "PSDB";
        }
        else if (aux.numero == "50")
        {
            aux.partido = "PSOL";
        }
        else if (aux.numero == "55")
        {
            aux.partido = "PSD";
        }
        else if (aux.numero == "65")
        {
            aux.partido = "PCdoB";
        }
        else {
            aux.partido = "Partido indefinido";
        }

        aux.votos = 0;

        listaP.push(aux);

        resposta = false;
        if (i < 4) {
            while (!resposta)
            {
                cout << "\nDeseja adicionar mais candidatos a prefeito?\n";
                cin >> resp;
                if (resp == "sim" || resp == "SIM" || resp == "Sim" || resp == "SIm" || resp == "sIM" || resp == "SiM" || resp == "siM")
                {
                    resposta = true;

                }
                else if (resp == "nao" || resp == "NAO" || resp == "Nao" || resp == "NAo" || resp == "nAO" || resp == "NaO" || resp == "naO")
                {
                    prefe = true;
                    resposta = true;
                }
                else {
                    cout << "resposta invalida\n";
                }
                system("cls");
            }
        }
        i++;

    }
    
    cout << "Serao adicionado os candidatos para vereador\n\n";
    i = 0;
    while (!vere && i <50)
    {
        cout << "Insira o nome do vereador para eleicao\n";
        cin >> auxV.nome;

        cout << "\nInsira o numero do vereador para eleicao\n";
        cin >> auxV.numero;

        auxV.votos = 0;

        listaV.push(auxV);

        resposta = false;
        if (i < 49) {
            while (!resposta)
            {
                cout << "\nDeseja adicionar mais vereadores?\n";
                cin >> resp;
                if (resp == "sim" || resp == "SIM" || resp == "Sim" || resp == "SIm" || resp == "sIM" || resp == "SiM" || resp == "siM")
                {
                    resposta = true;

                }
                else if (resp == "nao" || resp == "NAO" || resp == "Nao" || resp == "NAo" || resp == "nAO" || resp == "NaO" || resp == "naO")
                {
                    vere = true;
                    resposta = true;
                }
                else {
                    cout << "resposta invalida\n";
                }
                system("cls");
            }
        }
        i++;
    }
    while (!listaP.empty()) {

        votarP.push(listaP.top());
        listaP.pop();

    }

    while (!listaV.empty()) {

        votarV.push(listaV.top());
        listaV.pop();

    }


    cout << "votacao sera iniciada\n\n";

    system("pause");
    system("cls");

    while (!votacao) {
        votacaoV = false;
        while (!votacaoV) {
            cout << "\ninsira o numero do seu candidato para vereador\n";
            cout << "Digite 'branco' apra votar branco\n\n";
            cin >> voto;
            if (voto == "branco" || voto == "Branco" || voto == "BRANCO")
            {
                brancoV++;
            }
            else {
                while (voto != votarV.front().numero)
                {
                    auV.push(votarV.front());
                    votarV.pop();
                        
                    if (votarV.empty())
                    {
                        nuloV++;
                        break;
                    }
                }
            }

            while (!auV.empty())
            {
                votarV.push(auV.front());
                auV.pop();
            }

            if (voto == votarV.front().numero) {
                cout << endl << votarV.front().nome;
            }
        
            cout << endl << endl << "confirmar voto?\n";
            cin >> resp;
            if (voto != "branco" || voto == "Branco" || voto == "BRANCO"){
                if (resp == "sim" || resp == "SIM" || resp == "Sim" || resp == "SIm" || resp == "sIM" || resp == "SiM" || resp == "siM")
                {
                    votarV.front().votos++;
                    votacaoV = true;
                }
            }

            if (voto == "branco" || voto == "Branco" || voto == "BRANCO")
            {
                if (resp == "sim" || resp == "SIM" || resp == "Sim" || resp == "SIm" || resp == "sIM" || resp == "SiM" || resp == "siM") { votacaoV = true; }
            }

        }
        votacaoP = false;
        while (!votacaoP) {
            system("cls");
            cout << "insira o numero do seu candidato para prefeito\n";
            cout << "Digite 'branco' apra votar branco\n\n";
            cin >> voto;

            if (voto == "branco" || voto == "Branco" || voto == "BRANCO")
            {
                brancoP++;
            }
            else {
                while (voto != votarP.front().numero)
                {
                    auP.push(votarP.front());
                    votarP.pop();

                    if (votarP.empty())
                    {
                        nuloP++;
                        break;
                    }
                }
            }

            while (!auP.empty())
            {
                votarP.push(auP.front());
                auP.pop();
            }

            if (voto == votarP.front().numero) {
                cout << endl << votarP.front().partido;
                cout << endl << "Prefeito " << votarP.front().nome << endl << "Vice " << votarP.front().vice;
            }   cout << endl << endl << "confirmar voto?\n";;
            cin >> resp;
            if (voto != "branco") {
                if (resp == "sim" || resp == "SIM" || resp == "Sim" || resp == "SIm" || resp == "sIM" || resp == "SiM" || resp == "siM")
                {
                    votarP.front().votos++;
                    votacaoP = true;
                }
            }
            if (voto == "branco" || voto == "Branco" || voto == "BRANCO")
            {
                if (resp == "sim" || resp == "SIM" || resp == "Sim" || resp == "SIm" || resp == "sIM" || resp == "SiM" || resp == "siM") { votacaoP = true; }
            }

        }
        resposta = false;

        while (!resposta)
        {
            cout << "Votar novamente?\n";
            cin >> resp;
            if (resp == "sim" || resp == "SIM" || resp == "Sim" || resp == "SIm" || resp == "sIM" || resp == "SiM" || resp == "siM")
            {
                resposta = true;

            }
            else if (resp == "nao" || resp == "NAO" || resp == "Nao" || resp == "NAo" || resp == "nAO" || resp == "NaO" || resp == "naO")
            {
                votacao = true;
                resposta = true;
            }
            else {
                cout << "resposta invalida\n";
            }

            system("cls");
        }

    }
    while (!votarP.empty())
    {
        respP.push_front(votarP.front());
        votarP.pop();
    }
    while (!votarV.empty())
    {
        respV.push_front(votarV.front());
        votarV.pop();
    }
    cout << "Candidatos para vereadores: \n";
    while (!respV.empty())
    {
        cout << respV.front().nome << " " << respV.front().votos << " votos\n";

        if (respV.front().votos > venV.votos)
        {
            venV.votos = respV.front().votos;
            venV.nome = respV.front().nome;
        }

        respV.pop_front();
    }
    cout << endl << endl << endl;

    cout << "Candidatos para prefeito: \n";

    while (!respP.empty())
    {
        cout << respP.front().nome << " " << respP.front().votos << " votos\n";

        if (respP.front().votos > venP.votos)
        {
            venP.votos = respP.front().votos;
            venP.nome = respP.front().nome;
            venP.vice = respP.front().vice;
        }

        respP.pop_front();

    }

    cout << endl << endl << "votos brancos para prefeito: " << brancoP << endl;
    cout << "votos brancos para vereadores: " << brancoV << endl;
    cout << "votos nulos para prefeito: " << nuloP << endl;
    cout << "votos nulos para vereadores: " << nuloV << endl;

    cout << "\n\nvencedores\n\nNovo prefeito: " << venP.nome << "vice " << venP.vice << "\nVereador mais votado " << venV.nome;



}
