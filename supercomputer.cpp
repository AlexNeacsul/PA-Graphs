#include <bits/stdc++.h>

using namespace std;

#define NMAX 100001

int context_switch(int N, vector<vector<int>>& adj_list,
                            vector<int>& in_cnt,
                            vector<int>& data_sets, int init_data_set) {
    queue<int> queue1;
    queue<int> queue2;

    // Populez fiecare coada in functie de valoarea setului de date
    for (int i = 1; i <= N; i++) {
        if (in_cnt[i] == 0) {
            if (data_sets[i] != 1) {
                queue2.push(i);
            } else {
                queue1.push(i);
            }
        }
    }

    int context_switch_cnt = 0;
    int current_data_set = init_data_set;

    // Cat timp cel putin una dintre cozi nu este goala fac verificarile
    // necesare si incrementarile necesare pentru a obtine numarul de
    // context switch-uri
    while (!queue1.empty() || !queue2.empty()) {
        int current_task;

        // Verific din ce coada urmeaza sa scot urmatorul task si daca
        // coada respectiva este populata
        if (current_data_set == 1 && !queue1.empty()) {
            current_task = queue1.front();
            queue1.pop();
        } else if (current_data_set == 2 && !queue2.empty()) {
            current_task = queue2.front();
            queue2.pop();
        } else {
            // Daca respectiva coada este goala atunci incrementam
            // contorul de context switch-uri
            context_switch_cnt++;
            current_data_set = 3 - current_data_set;
            continue;
        }

        // Pentru fiecare task vecin al task-ului curent se decrementeaza
        // numarul de muchii care intra in el si daca acesta ajunge la zero
        // se adauga in coada corespunzatoare setului de date
        for (int nextTask : adj_list[current_task]) {
            --in_cnt[nextTask];

            if (!in_cnt[nextTask]) {
                if (data_sets[nextTask] != 1) {
                    queue2.push(nextTask);
                } else {
                    queue1.push(nextTask);
                }
            }
        }
    }

    // Intorc numarul de context switch-uri
    return context_switch_cnt;
}

int main() {
    int N, M, context_switch_cnt1, context_switch_cnt2;
    vector<int> data_sets(NMAX), in_cnt, aux_in_cnt;
    vector<vector<int>> adj_list(NMAX);

    // Deschid fisierul de in de unde citesc datele
    FILE *in = fopen("supercomputer.in", "rt");

    // Verific daca fisierul a fost deschis corect
    if (in == NULL) {
        fprintf(stderr, "Can't open in");
        return -1;
    }

    // Citesc datele din fisier
    fscanf(in, "%d", &N);
    fscanf(in, "%d", &M);

    for (int i = 1; i <= N; i++) {
        fscanf(in, "%d", &data_sets[i]);
    }

    in_cnt.resize(N + 1, 0);

    // Populez lista de adiacente si incrementez numarul de muchii care intra
    // in nodul respectiv
    for (int i = 0, u, v; i < M; i++) {
        fscanf(in, "%d", &u);
        fscanf(in, "%d", &v);

        adj_list[u].push_back(v);
        in_cnt[v]++;
    }

    // Inchid fisierul dupa ce termin citirea datelor
    fclose(in);

    // Copiez datale din in_cnt in vectorul auxiliar pe care o sa-l
    // folosesc in prima apelare a functiei
    aux_in_cnt.assign(in_cnt.begin(), in_cnt.end());

    // Apelez de doua ori functia, prima data cu valoarea 1 a setului
    // initial de date si a doua cu valoarea 2 a setului initial de date
    context_switch_cnt1 = context_switch(N, adj_list, aux_in_cnt, data_sets, 1);
    context_switch_cnt2 = context_switch(N, adj_list, in_cnt, data_sets, 2);

    // Deschid fisierul unde scriu rezultatul
    FILE *out = fopen("supercomputer.out", "wt+");

    // Verific daca fisierul a fost deschis corect
    if (out == NULL) {
        fprintf(stderr, "Can't open out");
        return -1;
    }

    // Scriu minimul obtinut dintre cele doua apelari ale functiei
    fprintf(out, "%d\n", min(context_switch_cnt1, context_switch_cnt2));

    // Inchid fisierul dupa ce scriu rezultatul final
    fclose(out);

    return 0;
}