#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Pago.h"
#include "Util.h"

PagoPtr crearPago(int idCuenta, int monto){
    PagoPtr p = (PagoPtr)obtenerMemoria(sizeof(Pago));
    p->idCuenta = idCuenta;
    p->monto = monto;

    return p;
}

PagoPtr destruirPago(PagoPtr pago){
    free(pago);
    return NULL;
}

void setMontoPago(PagoPtr pago, int monto){
    pago->monto = monto;
}


int getMontoPago(PagoPtr pago){
    return pago->monto;
}
