#ifndef KORTIT_H
#define KORTIT_H

/* Enum-maaritykset */
typedef enum {
    HERTTA = 1,
    RUUTU,
    RISTI,
    PATA
} Maa;

typedef enum {
    ASSA = 1,
    KAKKONEN,
    KOLMONEN,
    NELONEN,
    VIITONEN,
    KUUTONEN,
    SEISKA,
    KASI,
    YSI,
    KYMPPI,
    JATKA,
    ROUVA,
    KUNKKU
} Arvo;

/* Vakioarvot */
#define MAA_LKM 4
#define MAA_KOKO 13
#define KORTTI_LKM (MAA_LKM * MAA_KOKO)

/* Merkkijonotaulukot */
extern const char *MAIDEN_NIMET[MAA_LKM + 1];
extern const char *KORTTIEN_NIMET[MAA_KOKO + 1];

/* Struct-maaritys */
typedef struct {
    Maa maa;
    Arvo arvo;
} Kortti;

/* Funktiomaaritykset */
void tulostaKortti(Kortti kortti);
void tulostaKorttiOs(const Kortti *korttiOs);

#endif /* KORTIT_H */

