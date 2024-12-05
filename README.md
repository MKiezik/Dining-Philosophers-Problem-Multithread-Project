# Dwa rozwiązania problemu pięciu filozofów

Zad. 1. Podaj rozwiązanie problemu pięciu filozofów z możliwością zakleszczenia. Zaimplementuj pięć widelców przy pomocy pięcioelementowej tablicy muteksów (funkcje pthread_mutex_lock i pthread_mutex_unlock).  W rozwiązaniu tym filozof o numerze i=0...4 podnosi  najpierw widelec lewy (o numerze  i)  a  następnie widelec prawy (o numerze (i+1)%5).  Program powinien wypisywać na standardowe wyjście komunikaty (podniesienie i opuszczenie widelca, rozpoczęcie i zakończenie jedzenia oraz myślenia) dla każdego z filozofów. Myślenie i jedzenie symuluj przy pomocy funkcji usleep. Zademonstruj prowadzącemu wystąpienie zjawiska zakleszczenia.  

Zad. 2. Zmodyfikuj rozwiązanie zadania 1 przez wprowadzenie asymetrii. Niech jeden z filozofów (np. o numerze zero) próbuje podnieść najpierw prawy, a następnie lewy widelec. Czy przy takim rozwiązaniu może wystąpić zakleszczenie ? Czy może wystąpić zagłodzenie ?
