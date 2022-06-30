&copy; 2021-2022 Andrei Napruiu

# First PC Homework - Functions and static structures(Arrays, Matrix)

> **Mentions before start:**
> + The actual pdf with all the requirements for this homework can be found [here](https://github.com/andreinapruiu/pdfs-PC/blob/main/Programare_2021___Tema_1.pdf).
> + The README file included in the repo is just so the checker gives 100 points on this homework.
> + After reading what each problem does you can go on and [run the code](#how-to-run-the-code) or [check the problems](#how-to-run-the-checker).

# Contents:
1. [Short Description](#short-description)
1. [Problem 1](#on-the-fly-analysis)
2. [Problem 2](#natural-numbers-properties)
3. [Problem 3](#improving-scores)
4. [Problem 4](#nomogram-checker)

## Short description


## On the fly analysis

Dupa initializarile de rigoare, influentate de denumirile variabilelor din problema incepe algoritmul care rezolva cerinta data.
In primul rand, numele variabilelor(daca nu sunt sugestive) sunt explicate la punctul PS1 de mai jos.

Asa cum am fost atentionati, algoritmul nu poate folosi vectori pentru o alocare statica a memoriei, astfel ca am fost nevoit sa implementez o citire de valori consecutive. In cazul de fata am ales sa citesc 3 inaltimi ale copacilor date prin variabilele tree1, tree2, tree3. Aceasta citire mi-a creat o prima problema: daca se citesc de la bun inceput doar 1 sau 2 valori, cum se va rezolva problema. De aceea am implementat cazurile speciale in care N=1 SAU N=2. Astfel, algoritmul va putea trece toate testele date, cu afisarile corecte.
Pasul 2 in rezolvarea problemei a fost implementarea algoritmului. Dupa citirea celor 3 inaltimi am verificat prima oara daca tree2 poate fi un copac special. In caz afirmativ, incrementam numarul de copaci speciali, adaugam inaltimea copacului la suma finala si, pentru ca am citit primii 3 copaci stiu sigur ca tree 2 va fi pe pozitia 1, astfel ca ii verific inaltimea cu maximul copacilor speciali de pe pozitii impare(in caz afirmativ schimb valoarea maxima).
Ulterior incep o structura repetitiva care va citi de fiecare data un copac nou si va interschimba valorile variabilelor tree1, tree2 si tree3 astfel incat acestea sa ramana consecutive(metoda paharelor). Dupa reatribuirea valorilor in variabile continui verificarea specifica pentru un copac special(tree1<tree2 SI tree2>tree3). In caz afirmativ, ca mai devreme la primul pas, adaug la suma inaltimea, incrementez numarul de copaci speciali si incep o noua verificare: ce indice are noul copac special. In cazul in care indicele este impar, procesul este ca la primul pas. In cazul in care indicele este par, intervine o noua verificare: daca xmin_par nu si-a primit deja o alta valoare(diferita de -1 cum a fost initializat) si daca xmin_par>tree2 atunci xmin_par va lua valoarea inaltimii din tree 2.
Practic, in cazul in care nu a mai existat pana acum nici o valoarea minima, aceasta va fi data de primul copac special gasit pe o pozitie para. Daca a mai existat inainte o valoarea minima, ultima valoarea minima se compara cu candidatul actual si se inlocuieste in cazul in care cea din urma e mai mica.
Iteratia din structura repetitiva continua pana cand nu mai sunt valori de citit. La final se vor afisa valorile cerute, in ordinea lor.
Mentiune: pentru valoarea m_a ne folosim de atributul (double) pentru a schimba tipul de impartire dintre 2 numere intregi, astfel reusind sa facem afisarea unui numar real cu cu exact 7 zecimale.

PS1 : N, S, xmax_impar, xmin_impar, m_a sunt variabilele date exact in cerinta
	|- variabila specials_number retine numarul de copaci speciali
	|- variabilele tree1, tree2, tree3 reprezinta inaltimile a 3 copaci consecutivi




## Natural numbers properties

In primul rand, numele variabilelor din main(daca nu sunt sugestive) sunt explicate la punctul PS2 de mai jos.

Dupa citirea numarul N dat de cerinta, incepe algoritmul de rezolvare a problemei. In primul rand, avem nevoie de crearea numarului N cu cifrele ordonate descrescator. Astfel, am creat functia sort_high_to_low. In aceasta functie, numarul dat ca parametru este spart si adaugat intr-un vector(care va avea intotdeauna cel mult 10 elemente, cum este precizat in enunt). Ulterior, vectorul este sortat descrescator prin cel mai simplu algoritm de sortare. Dupa sortare, elementele ordonate descrescator sunt puse intr-o variabiala(new_N) care va retine practic numarul dat ca parametru cu cifrele sale ordonate descrescator(ex.: numarul 14325 este spart pe cifre si adaugat in vector. Dupa sortare, vectorul va fi de forma 5 4 3 2 1, iar dupa adaugarea in noua variabila, functia va returna numarul 54321).
Pentru n_crescator ne folosim de n_descrescator si o noua functie(mirrored) care calculeaza oglinditul numarului. Practic, numarul N cu cifrele ordonate crescator este inversul numarului n_descresctor. Astfel scapam de problema zerourilor din numere(in cazul numarului 3500, n_descrescator este 5300,  n_crescator este 35, fara zerouri in fata).
Initializam variabila k cu 0 pentru a putea numara cate numere noi sunt create. In structura repetitiva de tip while, conditia ok == 0 reprezinta conditia de continuare a procesului. ok=1 arata faptul ca au fost gasite 2 numere identice in vectorul creat. Pana la gasirea celor 2 elemente identice care dau inceputul si sfarsitul unei perioada, ne folosim intai de n_crescator si n_descrescator pentru a calcula de fiecare data un alt numar ce va trece prin acelasi proces.
In for cautam cu exactitate 2 elemente egale din vector. In cazul in care nu exista, inseamna ca mai trebuie parcursi niste pasi din scadere. Astfel ca n_crescator si n_descrescator isi schimba valorile dupa ultimul numar creat.
In cazul in care exista apar mai multe consecinte:
	a) ok trebuie sa devina 1 pentru a opri definitiv repetitia procesului
	b) variabila left va retine indicele i la care s-a gasit ultimul element adaugat in vector(pentru afisarea ulterioara a secventei)
	c) variabila right va retine pozitia k-1 care reprezinta ultimul element dinaintea inceperii unei noi secvente perioada
	d) varibila m(dimensiunea secventei) va fi data de diferenta right-left(destul de self explanatory)
	e) variabila k va deveni in sfarsit cine trebuia sa fie de la inceput, diferenta dintre numarul de numere existente in vector, m si 1(pentru valoarea exacta) => k este numarul de operatii pana la inceperea secventei repetitive
	f) break; pentru a opri repetarea procesului

La final, se afiseaza valorile in ordinea in care sunt cerute.

PS2 : N, n_crescator, n_descrescator, m, k sunt variabilele mentionate in cerinta
	|- variabilele left si right vor retine indicii de la care porneste, respectiv se opreste secventa de numere din "perioada"
	|- V[NMAX] va retine toate numerele create pana la finalizarea programului, DIM va fi dimensiunea vectorului ce se incrementeaza la fiecare pas 
	|- ok va reprezenta variabila de stop in crearea numerelor prin diferente succesive




## Improving scores

In primul rand, numele variabilelor din main(daca nu sunt sugestive) sunt explicate la punctul PS3 de mai jos.

Incep cu citirea datelor asa cum sunt date in cerinta. Ulterior se abordeaza cazul special(cu afisarea lui -1): daca toate elementele din vectorul de note sunt 10 si totusi punctajul studentului nu depaseste punctajul minim, e clar ca nu se mai pot face modificari, astfel ca oprim executia programului si afisam -1.
La cazul special am calculat, odata cu verificarea elementelor egale cu 10, si punctajul studentului, pe care il voi folosi mai departe.
Pentru o executie mai rapida si o intelegere facila a algoritmului, am ales sa elimin din vectorul de note toate elementele egale cu 10(deoarece ele nu mai sunt necesare maririi punctajului) si toate punctele credit aferente din vectorul de puncte de credit. Pentru asta am folosit functia delete_element care este destul de self-explanatory: sterge din vectorul dat ca parametru elementul aflat pe pozitia data tot ca parametru. Dupa executarea functiei, decrementez valoarea lui n cu o unitate(deoarece am eliminat un element din vector).
Odata cu eliminarea valorilor de 10 este necesar sa gasim maximul dintre toate ponderile posibile, pentru a avea un numar minim de materii la care crestem nota. Destul de simplu, calculez prin parcurgerea vectorilor x si c ponderile si le salvez pe rand in variabila p_new(cum este explicat la PS3). Ulterior, compar noua pondere cu maximul anterior(initializat la inceput cu 0) si salvez, daca este cazul, noul maxim in variabila maxim. Odata gasit un astfel de maxim, ii retin pozitia.
Dupa gasirea maximului sigrid_lines[NMAX][NMAX], grid_columns[NMAX][NMAX], gigel[NMAX][NMAX] a pozitiei acestuia si dupa adaugare acestui maxim la punctajul studentului, elimin din vectori elementele de pe pozitiile date de pos_max(practic elementul din x corespunzator lui pos_max a atins valoarea 10 si nu mai poate fi marit, astfel ca eliminam atat x[pos_max], cat si c[pos_max]).
De asemenea, crestem numarul de materii la care se face marirea cu o unitate. Mai apoi verificam daca punctajul actual este cel dorit, in caz afirmativ afisam valoarea lui nr si oprim programul. Altfel, de acum incolo, cat timp punctajul nu este cel dorit si cat timp mai exista note in vectorul de note, vom executa aceeasi pasi, pe rand, pentru aflarea numarului minim de materii la care este necesara marirea.

Nota: primul pas putea fi executat tot in structura repetitiva, dar am vrut sa fie clara explicatia programului

PS3 : n, x[NMAX], c[NMAX], p_min sunt variabilele mentionate in cerinta
	|- p reprezinta punctajul studentului(initial inainte de modificari, ulterior modificat odata cu cresterea notelor) 
	|- nr este numarul de materii la care este necesara o marire
	|- all_10 este o variabila de verificare(daca toate notele sunt 10)
	|- maxim este variabila in care se retine maximul de puncte posibile, pos_max este pozitia acestui maxim in vectori
	|- p_new este punctajul dat de pondere(ex.: studentul are nota 4 la o materie de 6 puncte, deci in p_new se va retine (10 - 4) * 6 reprezentand punctajul pe care l-ar putea adauga la nota sa finala daca isi mareste nota la 10)




## Nomogram checker

In primul rand, numele variabilelor din main(daca nu sunt sugestive) sunt explicate la punctul PS4 de mai jos.

Prima citire, cea a numarului T este cea mai importanta(pe care eu o uitasem din greseala la inceput). In functie de numarul T se da numarul de puzzle-uri pe care Gigel vrea sa le rezolve.
Incep prin a crea o structura repetitiva, care in functie de valoarea ramasa in T, mai accepta sau nu citirea unor noi valori pentru rezolvarea unui nou puzzle(variabila T se decrementeaza cu o unitate dupa citirea unui puzzle).
Dupa citirea valorilor N si M in ordinea data, apelez cele 2 functii de citire:
	a) functia read_everything care citeste intr-o matrice cu n linii si dimensiunea coloanelor variabia restrictiile de linii sau de coloane date in cerinta(restrictiile sunt citite pe rand)
	b) functia read_matrix care face o citire normala pentru matricea data de Gigel spre verificare

In variabila ok_lines pastrez valoarea returnata de functia verify_lines care reprezinta functia care verifica nomograma data de Gigel. In cazul in care ok_lines este 1, pentru puzzle-ul curent afisez mesajul "Corect" si trec pe linia urmatoare pentru mesajul urmator. In caz contrar(ok_lines = 0), afisez "Eroare" si trec pe linia urmatoare.
Mentiune: este suficient sa verific daca nomograma este corecta doar pe linii, pentru ca daca nu ar fi, nici coloanele nu ar avea valorile corecte(astfel scutesc niste timp de executie).

Functia verify_lines verifica in functie de restrictiile de linie, daca nomograma data este corecta. Variabila nr_1 va retine cati de 1 sunt intr-o secventa de 1 consecutivi, variabila k va retine la ce element din matricea grid_lines ne aflam pentru verificarea lungimii unei secvente de 1 consecutivi.
Primul si al doilea for se leaga pentru parcurgerea matricei lui Gigel. Odata initializata cu 0 variabila nr_1, in matricea lui gigel, folosind structura while, sarim peste indicii elementelor egale cu 0. Dupa finalizarea acestei operatii, indicele j va arata spre un element de pe linia i care are valoarea 1. De aici, printr-o alta structura while, numaram cate elemente consecutive au valoarea 1.
Dupa numare, verificam daca in variabila nr_1 exista o valoarea diferita de 0. In caz afirmativ, verificam daca valoarea din nr_1 difera de cea din grid_lines[i][k](a k-a restrictie), in caz afirmativ returnam valoarea 0 si oprim functia. Altfel, incrementam valoarea lui k pentru verificarea urmatoarei secvente.
Daca pana la finalul parcurgerii matricei lui Gigel nu s-a returnat valoarea 0, inseamna ca matricea este corecta si returnam valoarea 1.

PS4 : N, M, T - o parte din variabilele date in cerinta
	|- grid_lines[NMAX][NMAX], grid_columns[NMAX][NMAX] sunt matricile in care se vor salva restrictiile pentru linii si coloane
	|- gigel[NMAX][NMAX] este matricea data de Gigel
	|- ok_lines in care se pastreaza valoarea 1 daca nomograma incarcata de Gigel este corecta, 0 in caz contrar

## How to run the code?
1. Download the files as shown in the repo;
2. Open a terminal and change the current directory with the one containing the code;
3. Run the following commands for each problem:
	- make
	- ./'name of the generated executable corresponding to the chosen problem'
	- the set of numbers(data)

### Example for the first problem
```bash
student@pc:~$ make
gcc -Wall -Wextra -std=c99 ninel.c -o ninel
gcc -Wall -Wextra -std=c99 codeinvim.c -o codeinvim
gcc -Wall -Wextra -std=c99 vectsecv.c -o vectsecv
gcc -Wall -Wextra -std=c99 nomogram.c -o nomogram
student@pc:~$ ./ninel 
9
3 1 3 2 2 5 2 4 2
12
4.0000000
5
3
```

> The names of the generated executables corresponing each to a different problem are, in order: **ninel, codeinvim, vectsecv, nomogram** as seen in the code above.<br>

## How to run the checker?

1. Download the files as shown in the repo;
2. Open a terminal and change the current directory with the one containing the code;
3. Run the following command:

```bash
student@pc:~$ ./check
```

> You will be prompted with a lot of lines verifying a number of inputs for each problem. All the inputs can be found in **taks** folder.

If you want to verify the coding style(based on **Google's coding style**, run:
```bash
student@pc:~$ cs/cs.sh *
```

> It will check the coding style on all the files in the tree and print a message inside the command line if it found something irregular.
