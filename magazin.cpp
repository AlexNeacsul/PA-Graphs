#include <bits/stdc++.h>

#define NMAX 100005

using namespace std;

int t = 0;
vector<int> path, pos, start_time, finish_time;
vector<bool> visited;

// Algoritmul de dfs
void dfs(int node, vector<int>adj[NMAX]) {
    // Setez timpul de start pentru nodul curent
    t++;
    start_time[node] = t;

    // Adaug nodul curent in vectorul de path
    // pentru a tine evidenta drumului parcurs
    path.push_back(node);

    // Actualizez pozitia nodului
    pos[node] = (path.size() - 1);

    for (int i = 0; i < (int)adj[node].size(); i++) {
        if (visited[adj[node][i]] == false) {
            visited[adj[node][i]] = true;
            dfs(adj[node][i], adj);
        }
    }

    // Setez timpul de final pentru nodul curent
    finish_time[node] = t;
}

int main(void) {
    int N, Q, *D, *E;
    vector<int> adj[NMAX];

    // Deschid fisierul de in de unde citesc datele
    FILE *in = fopen("magazin.in", "rt");

    // Verific daca fisierul a fost deschis corect
    if (in == NULL) {
        fprintf(stderr, "Can't open in");
        return -1;
    }

    // Citesc datele
    fscanf(in, "%d", &N);
    fscanf(in, "%d", &Q);

    for (int i = 1, x; i < N; i++) {
        fscanf(in, "%d", &x);
        adj[x].push_back(i + 1);
    }

    D = (int *)malloc(Q * sizeof(int));

    if (D == NULL) {
        fprintf(stderr, "Can't allocate D");
        return -1;
    }

    E = (int *)malloc(Q * sizeof(int));

    if (E == NULL) {
        fprintf(stderr, "Can't allocate E");
        return -1;
    }

    for (int i = 0; i < Q; i++) {
        fscanf(in, "%d", &D[i]);
        fscanf(in, "%d", &E[i]);
    }

    // Inchid fisierul pentru ca nu mai avem nevoie de el
    fclose(in);

    // Initializez vectorii
    path.reserve(N + 1);
    pos.resize(N + 1, -1);
    start_time.resize(N + 1, -1);
    finish_time.resize(N + 1, -1);
    visited.resize(N + 1, false);

    // Aplic algoritmul de dfs de la sursa
    dfs(1, adj);

    // Deschid fisierul unde urmeaza sa scriem rezultatele
    FILE *out = fopen("magazin.out", "wt");

    // Verific daca fisierul a fost deschis corect
    if (out == NULL) {
        fprintf(stderr, "Can't open out");
        return -1;
    }

    // Verific pentru fiecare nod cum este numarul de expedieri
    // consecutive fata de diferenta dintre timpul de sfarsit si
    // timpul de inceput pentru nodul respectiv
    for (int i = 0; i < Q; i++) {
        // Daca numarul de expedieri consecutive este mai mare
        // afisez -1. Daca este mai mic sau egal atunci afisez
        // nodul care se afla pe pozitia pos[D[i]] + E[i] din path.
        if (E[i] <= (finish_time[D[i]] - start_time[D[i]])) {
            fprintf(out, "%d\n", path[(pos[D[i]] + E[i])]);
        } else {
            fprintf(out, "-1\n");
        }
    }

    // Inchid fisierul dupa ce scriem in el
    fclose(out);

    // Eliberez memoria alocata
    free(D);
    free(E);

    return 0;
}
