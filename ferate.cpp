#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> graph, rev_graph, dir_acycl_graph;
stack<int> stck;
vector<bool> visited;
vector<int> component;

// Folosesc primul algoritm de dfs pentru
// realizarea soratarii topologice
void dfs1(int node) {
    visited[node] = true;
    for (int i : graph[node]) {
        if (!visited[i]) {
            dfs1(i);
        }
    }
    stck.push(node);
}

// Folosesc al doilea dfs pentru componentele
// tare conexe
void dfs2(int node, int component_Id) {
    visited[node] = true;
    component[node] = component_Id;
    for (int i : rev_graph[node]) {
        if (!visited[i]) {
            dfs2(i, component_Id);
        }
    }
}

int main() {
    int N, M, S, cnt = 0, components = 0;
    vector<int> in_cnt;

    // Deschid fisierul de in de unde citesc datele
    FILE *in = fopen("ferate.in", "rt");

    // Verific daca fisierul a fost deschis corect
    if (in == NULL) {
        fprintf(stderr, "Can't open in");
        return -1;
    }

    // Citesc datele din fisier
    fscanf(in, "%d", &N);
    fscanf(in, "%d", &M);
    fscanf(in, "%d", &S);

    // Decrementez pentru ca indexex nodurile de la 0
    S--;

    // Initializez vectorii
    graph.resize(N);
    rev_graph.resize(N);
    visited.resize(N, false);
    component.resize(N);

    for (int i = 0; i < N; i++) {
        graph[i] = vector<int>();
        rev_graph[i] = vector<int>();
    }

    for (int i = 0, u, v; i < M; i++) {
        fscanf(in, "%d", &u);
        fscanf(in, "%d", &v);
        // Decrementez din acelasi motiv ca la S
        u--;
        v--;
        graph[u].push_back(v);
        rev_graph[v].push_back(u);
    }

    // Inchid fisierul de input dupa ce citesc datele
    fclose(in);

    // Apelez functia dfs1 pentru a realiza o parcurgere
    // in adancime de la fiecare nod nevizitat
    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            dfs1(i);
        }
    }

    // Resetez vectorul de visited si parcurg stiva
    // rezultata din prima parcurgere in adancime
    fill(visited.begin(), visited.end(), false);

    while (!stck.empty()) {
        int node = stck.top();
        stck.pop();

        // Apelez functia dfs2 pentru a calcula
        // componentele tare conexe si a le
        // asocia nodurilor
        if (!visited[node]) {
            dfs2(node, components++);
        }
    }

    // Redimensionez matricea pentru nou numar
    // de componente tare conexe
    dir_acycl_graph.resize(components);

    for (int i = 0; i < components; i++) {
        dir_acycl_graph[i] = vector<int>();
    }

    // Construiesc dir_acycl_graph pe baza asocierii
    // realizate anterior cu ajutorul vectorului component
    for (int i = 0; i < N; i++) {
        for (int j : graph[i]) {
            if (component[i] != component[j]) {
                dir_acycl_graph[component[i]].push_back(component[j]);
            }
        }
    }

    // Redimensionez vectorul pentru a numara intrarile in
    // fiecare componenta tare conexa
    in_cnt.resize(components, 0);

    for (int i = 0; i < components; i++) {
        for (int j : dir_acycl_graph[i]) {
            in_cnt[j]++;
        }
    }

    // Parcurg dir_acycl_graph si numar componentele care
    // nu au nicio intrare si care nu corespund componentei
    // in care se afla nodul de inceput
    for (int i = 0; i < components; i++) {
        if (!in_cnt[i] && i != component[S]) {
            cnt++;
        }
    }

    // Deschid fisierul de in de unde citesc datele
    FILE *out = fopen("ferate.out", "wt+");

    // Verific daca fisierul a fost deschis corect
    if (out == NULL) {
        fprintf(stderr, "Can't open out");
        return -1;
    }

    // Scriu raspunsul final
    fprintf(out, "%d\n", cnt);

    // Inchid fisierul dupa ce scriu rezultatul final
    fclose(out);

    return 0;
}