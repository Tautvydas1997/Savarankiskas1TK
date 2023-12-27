
Savarankiskas
Sisteminio programavimo savarankiskas darbas nr. 1

V0.1
Pirmoji programos versija leidžia pridėti studentus rankiniu būdu.

Programa turi galimybe automatiškai sugeneruoti studento rezultatus.

Yra galimybė spausdinti rezultatus.

Rezultatai spausdinami formatuotose eilutėse.

Meniu pagalba palengvina vartotojo darbą su programa.

Programa leidžia pasirinkti kuriuo būdu skaičiuoti galutinį balą.

Paskutinis versijos atnaujinimas leidžia skaityti duomenis iš tekstinio failo.

Nuskaičius studentų informaciją iš failo, studentai rūšiuojami pagal pavardę ir spausdinami į ekraną su galutiniu balu apskaičiuotu dviemis būdais.

Try/Catch panaudotas išvengti klaidų kai skaičiuojant galutinio balo vidurkį gali pasitaikyti dalyba iš nulio.

Kodas suskirstytas į atskirus failus. Kievienas .cpp failas turi savo antraštinį failą.

V0.2
Sukurta funkcija generuoti studentams su atsitiktiniais balais.

Kuriant failą reikia nurodyti kiek studentų sugeneruoti.

Pridėtas funkcionalumas tudentams skaityti iš failo, sugrupuoti į dvi grupes: kietekus ir vargšiukus. Kietekai - studentai su didesniu arba lygiu penketui galutiniu balu. Vargsiukai - studentai su mazesniu nei 5 galutiniu balu.

Programa apdorojusi duomenis, dvi grupes studentų išveda į du skirtingus failus.

Programa taip pat atvaizduoja laiką kiek užtruko atlikti kiekvieną iš aukščiau išvardintų veiksmų.

Laiko vidurkis:
10 000 studentų:
Sukurti failą 178ms

Nuskaityti duomenis iš failo: 238ms

Sugrupuoti studentus: 21ms

Įrašyti studentus į du failus: 109ms

100 000 studentų:
Sukurti failą 1626ms

Nuskaityti duomenis iš failo: 2381ms

Sugrupuoti studentus: 241ms

Įrašyti studentus į du failus: 897ms

1000 000 studentų:
Sukurti failą 16311ms

Nuskaityti duomenis iš failo: 23653ms

Sugrupuoti studentus: 5593ms

Įrašyti studentus į du failus: 8875ms

10 000 000 studentų:
Sukurti failą 161133ms

Nuskaityti duomenis iš failo: 280276ms

Sugrupuoti studentus: 52947ms

Įrašyti studentus į du failus: 89691ms

Skirtingi konteinerių tipai
Buvo atlikti du 'commits' vienas su perdaryt programa iš vector į deque ir kitas iš deque į list. Abu papildomi variantai buvo pratestuoti. Naudojant list konteinerius, pvz milijono dydzio failas buvo surusiuotas dvigubai sparčiau nei naudojant vector. Kitų didelių skirtumų nepastebėjau. Su vector konteineriais naudojau reserve() funkciją, kad automatiškai būtų išskiriama daugiau vietos konteineriui. Tikriausiai dėl to didelio skirtumo tarp deque ir vector nepastebėjau (deque kai kur nusileido vector konteineriams).

V1.0
Pirma skirstymo, rūšiavimo strategija buvo implementuota ankstesneje versijoje.

Šioje versijoje buvo įgyvendinta antroji strategija: sukuriant tik viena nauja konteinerį ir ištrinant įrašą iš senojo konteinerio.

Naudojant antrąją strategiją rūšiavimui, geriausiai pasirodė list konteinerio tipas. Pvz. 10 milijonų studentų išrūšiavo per 27,4 sekundės, kai vektorius pirmuoju būdu užtruko 53 sekundes. Plius naudojo mažiau RAM atminties.

Deque ir Vector antruoju būdu pasirodė du ir daugiau kartų lėčiau nei List konteinerių tipas.
