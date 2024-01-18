# PA-Graphs
323CA
Neacșu Alexandru-Catalin

                                            ~Descriere cod~
        ~Supecomputer~

        In functia context_switch realizez algoritmul principal pentru rezolvarea problemei.In functie folosesc doua cozi in care
    salvez task-urile in functie de valoarea setului de date al respectivului task. Initializez contorul de schimbare de context
    si variabila current_data_set cu setul de date initial. Dupa intra in bucla while unde cat timp macar o coada este populata 
    se verifica daca coada corespunzatoare setului de date curent nu este goala. Daca este goala atunci incrementez contorul de
    schimbare de context, daca nu este goala atunci extrag un task din coada corespunzatoare setului de date curent. Pentru fiecare
    task vecin al task-ului curent se decrementeaza numarul de muchii care intra in el si daca acesta ajunge la zero se adauga in
    coada corespunzatoare setului de date. La finalul functiei intorc numarul de schimbari de context care a avut loc.
        In functia main intai am declarat variabilele pe care urmeaza sa le folosesc. Dupa deschid fisierul din care urmeaza sa citesc
    valorile. Verific daca fisierul a fost deschis corespunzator si daca da, incep si citesc valorile. Dupa ce adaug un nou element in
    lista de adiacenta incrementez si numarul de muchii care intra in respectivul task. Dupa ce termin de citit toate datele si de
    construit lista de adiacenta copiez datele din vectorul in_cnt intr-un alt vector auxiliar pentru a putea refolosi datele. Apelez
    functia context_switch de doua ori, o data cu vectorul auxiliar si cu valoarea 1 a setului de date initial, si a doua oara cu
    vectorul in_cnt si cu valoarea 2 a setului de date initial. Dupa deschid fisierul de output unde urmeaza sa scriu rezultatul final.
    Verific daca acesta a fost deschis corespunzator si daca da atunci scriu in el minimul dintre prima si a doua apelare a functiei
    context_switch, apoi inchid fisierul de output si opresc programul.
        Complexitatea spatiala este O(N + M).
        Complexitatea temporala este O(N + M).

        ~Ferate~

        Intai am declarat variabilele globale pe care urmeaza sa le folosesc. Am folosit doua functii de parcurgere in adancime
    dfs1 si dfs2. Prima functie o folosesc pentru realizarea sortarii topologice, iar a doua functie pentru componentele tare conexe.
    Aceste doua functii implementeaza algoritmul lui Kosaraju.
        In functia main intai am declarat valorile locale pe care urmeaza sa le folosesc. Dupa deschid fisierul din care urmeaza sa citesc
    valorile. Verific daca fisierul a fost deschis corespunzator si daca da, incep si citesc valorile. Dupa initializez vectorii declarati
    global. Dupa ce citesc toate datele din fisierul de input, inchid fisierul. Apelez functia dfs1 pentru a realiza o parcurgere in
    adancime pentru fiecare nod nevizitat. Dupa resetez vectorul de visited si parcurg stiva rezultata in urma apelarii functiei dfs1.
    Dupa, cat timp stiva nu este goala extrag un nod si apelez functia de dfs2 pentru a calcula componentele tare conexe si a le asocia
    nodurilor. Redimensionez matricea pentru nou numar de componente tare conexe si o construiesc pe baza asocierii realizate dupa apelarea
    functiei dfs2. Redimensionez vectorul pentru a numara intrarile in fiecare componenta tare conexa. Parcurg dir_acycl_graph si numar 
    componentele care nu au nicio intrare si care nu corespund componentei in care se afla nodul de inceput. Dupa deschid fisierul de output
    unde urmeaza sa scriu rezultatul final. Verific daca acesta a fost deschis corespunzator si daca da atunci scriu in el numarul de rail-uri.
        Complexitatea spatiala este O(N + M).
        Complexitatea temporala este O(N + M).


        ~Teleportare~

        Din cauza lipsei de timp nu am reusit sa rezolv aceasta problema dar cred ca se putea rezolva aplicand Dijkstra.

        ~Magazin~

        Intai am declarat variabilele globale pe care urmeaza sa le folosesc. Am folosit algoritmul de dfs pentru rezolvarea problemei. 
    In algoritm am incrementat timpul t si setez start_time pentru nodul respectiv. Adaug nodul in vectorul path pentru a putea tine 
    evidenta traseului parcurs. Actualizez pozitia nodului in vectorul pos si pentru fiecare vecin nevizitat al nodului curent apelez
    recursiv functia si la final setez finish_time pentru nodul curent.
        In functia main intai declar variabilele locale pe care urmeaza sa le folosesc. Dupa deschid fisierul din care urmeaza sa citesc
    valorile. Verific daca fisierul a fost deschis corespunzator si daca da, incep si citesc valorile. Aloc memorie pentru vectorii D si E.
    Dupa ce citesc toate datele din fisierul de input, inchid fisierul. Initializez vectorii declarati globali. Apelez functia dfs pentru nodul
    1 si pentru a calcula si salva timpii de inceput si sfarsit pentru fiecare nod. Dupa deschid fisierul de output unde urmeaza sa scriem
    raspunsul final. Verific daca fisierul a fost deschis corespunzator si daca da verific pentru fiecare nod cum este numarul de
    expedieri consecutive fata de diferenta dintre timpul de sfarsit si timpul de inceput pentru nodul respectiv. Daca numarul de expedieri
    consecutive este mai mare afisez -1. Daca este mai mic sau egal atunci afisez nodul care se afla pe pozitia pos[D[i]] + E[i] din vectorul
    path. "pos[D[i]] + E[i]" reprezinta distanta parcursa de pe pozitia nodului curent dupa numarul de expedieri consecutive. Dupa ce afisez
    pentru fiecare nod valorile respective inchid fisierul de output. Dupa eliberez memoria alocata dinamic pentru vectorii D si E si opresc
    programul.
        Complexitatea spatiala este O(N).
        Complexitatea temporala este O(N).

                                            ~Feedback~

    Tema a fost de un nivel mediu spre ridicat ca dificultate. Mi-a placut sa lucrez la tema. Consider ca laboratul a fost foarte
important in rezolvarea temei. Consider ca am reusit sa inteleg mai bine materia.
