#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

DblLista *dl_luo(void) {
    DblLista *uusi = (DblLista *)malloc(sizeof(DblLista));
    if(uusi == NULL) {
        return NULL;
    }
    uusi->paa = NULL;
    uusi->n = 0;
    return uusi;
}

void dl_tuhoa(DblLista *lista) {
    DblSolmu *s;
    DblSolmu *vapautettava;
    if (lista == NULL) return;
    s = lista->paa;
    while (s != NULL) {
        vapautettava = s;
        s = s->seur;
        free(vapautettava);
    }
    free(lista);
}

DblSolmu *dl_lisaaEteen(DblLista *lista, double arvo) {
    DblSolmu *uusi;
    if(lista == NULL) return NULL;
    uusi = (DblSolmu *)malloc(sizeof(DblSolmu));
    if(uusi == NULL) return NULL;
    uusi->data = arvo;
    uusi->seur = lista->paa;
    lista->paa = uusi;
    lista->n++;
    return uusi;
}

double dl_poistaEdesta(DblLista *lista) {
    DblSolmu *poistettava;
    double arvo;
    if(lista == NULL || lista->paa == NULL) return 0.0;
    poistettava = lista->paa;
    arvo = poistettava->data;
    lista->paa = poistettava->seur;
    free(poistettava);
    lista->n--;
    return arvo;
}

void dl_tulosta(const DblLista *lista) {
    DblSolmu *s;
    if(lista == NULL) return;
    printf("Lista:");
    s = lista->paa;
    while(s != NULL) {
        printf(" %.1f", s->data);
        s = s->seur;
    }
    printf("\n");
}

double dl_alkio(const DblLista *lista, size_t i) {
    DblSolmu *s;
    size_t idx;
    if(lista == NULL) return 0.0;
    if(i >= lista->n) return 0.0; /* laiton indeksi */
    s = lista->paa;
    idx = 0;
    while(s != NULL && idx < i) {
        s = s->seur;
        idx++;
    }
    if(s == NULL) return 0.0;
    return s->data;
}

DblSolmu *dl_lisaa(DblLista *lista, size_t i, double arvo) {
    DblSolmu *uusi;
    DblSolmu *edellinen;
    DblSolmu *nykyinen;
    size_t idx;

    if(lista == NULL) return NULL;
    
    uusi = (DblSolmu *)malloc(sizeof(DblSolmu));
    if(uusi == NULL) return NULL;
    uusi->data = arvo;
    uusi->seur = NULL;

    if(lista->n == 0) {
        /* Lista on tyhjä, uusi solmu listan alkuun */
        lista->paa = uusi;
        lista->n = 1;
        return uusi;
    }

    if(i == 0) {
        /* Lisäys listan alkuun */
        uusi->seur = lista->paa;
        lista->paa = uusi;
        lista->n++;
        return uusi;
    }

    edellinen = NULL;
    nykyinen = lista->paa;
    idx = 0;
    while(nykyinen != NULL && idx < i) {
        edellinen = nykyinen;
        nykyinen = nykyinen->seur;
        idx++;
    }

    edellinen->seur = uusi;
    uusi->seur = nykyinen;

    lista->n++;
    return uusi;
}

double dl_poista(DblLista *lista, size_t i) {
    DblSolmu *poistettava;
    DblSolmu *edellinen;
    double arvo;
    size_t idx;

    if(lista == NULL || lista->paa == NULL) return 0.0;
    if(i >= lista->n) return 0.0; /* laiton indeksi */

    poistettava = lista->paa;
    edellinen = NULL;
    idx = 0;

    while(poistettava != NULL && idx < i) {
        edellinen = poistettava;
        poistettava = poistettava->seur;
        idx++;
    }

    if(poistettava == NULL) {
        return 0.0;
    }

    arvo = poistettava->data;

    if(edellinen == NULL) {
        /* Poistetaan listan ensimmäinen solmu */
        lista->paa = poistettava->seur;
    } else {
        edellinen->seur = poistettava->seur;
    }

    free(poistettava);
    lista->n--;

    return arvo;
}

