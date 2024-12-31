#ifndef LISTA_H
#define LISTA_H

#include <stddef.h> /* size_t */

typedef struct DblSolmu {
    double data;
    struct DblSolmu *seur;
} DblSolmu;

typedef struct {
    DblSolmu *paa;
    size_t n;
} DblLista;

/* Rakentaa uuden tyhjän listan ja palauttaa osoittimen siihen */
DblLista *dl_luo(void);

/* Vapauttaa listan kaikki solmut sekä itse DblLista-rakenteen */
void dl_tuhoa(DblLista *lista);

/* Lisää uuden arvon listan alkuun */
DblSolmu *dl_lisaaEteen(DblLista *lista, double arvo);

/* Poistaa listan ensimmäisen alkion ja palauttaa sen arvon. Palauttaa 0 jos lista on tyhjä */
double dl_poistaEdesta(DblLista *lista);

/* Tulostaa listan arvot */
void dl_tulosta(const DblLista *lista);

/* Uudet funktiot: */

/* Palauttaa listan i. solmun arvon. Palauttaa 0, jos i on laiton. */
double dl_alkio(const DblLista *lista, size_t i);

/* Lisää arvon "arvo" listaan niin, että se tulee listan indeksin i solmun eteen.
   Jos i >= lista->n, lisäys tapahtuu listan loppuun. Palauttaa lisätyn solmun osoittimen. */
DblSolmu *dl_lisaa(DblLista *lista, size_t i, double arvo);

/* Poistaa indeksin i solmun listasta ja palauttaa sen arvon. Palauttaa 0 jos i on laiton */
double dl_poista(DblLista *lista, size_t i);

#endif /* LISTA_H */

