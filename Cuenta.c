#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "Lista.h"
#include "Pila.h"
#include "Cola.h"
#include "Cuenta.h"
#include "Util.h"

CuentaPtr crearCuenta(int idCuenta, int idClienteCuenta, char NIP[5], int nTipoCuenta, int saldo, int limiteCredito, PtrPila pilaMovimientos, PtrCola colaPagos){
    CuentaPtr c = (CuentaPtr)obtenerMemoria(sizeof(Cuenta));
    strcpy(c->NIP,NIP);
    c->idCuenta = idCuenta;
    c->idClienteCuenta = idClienteCuenta;
    c->nTipoCuenta = nTipoCuenta;
    c->saldo = saldo;
    c->limiteCredito = limiteCredito;
    c->pilaMovimientos = pilaMovimientos;
    c->colaPagos = colaPagos;

    return c;
}

CuentaPtr destruirCuenta(CuentaPtr cuenta){
    free(cuenta);
    return NULL;
}

int getIdCuenta(CuentaPtr cuenta){
    return cuenta->idCuenta;
}

void setIdCuenta(CuentaPtr cuenta, int idCuenta){
    cuenta->idCuenta = idCuenta;
}

int getIdClienteCuenta(CuentaPtr cuenta){
    return cuenta->idClienteCuenta;
}

void setIdClienteCuenta(CuentaPtr cuenta, int idClienteCuenta){
    cuenta->idClienteCuenta = idClienteCuenta;
}

char* getNip(CuentaPtr cuenta){
    return cuenta->NIP;
}

void setNip(CuentaPtr cuenta, char NIP[5]){
    strcpy(cuenta->NIP,NIP);
}

int getNtipoCuenta(CuentaPtr cuenta){
    return cuenta->nTipoCuenta;
}

void setNtipoCuenta(CuentaPtr cuenta, int nTipoCuenta){
    cuenta->nTipoCuenta = nTipoCuenta;
}

int getSaldo(CuentaPtr cuenta){
    return cuenta->saldo;
}

void setSaldo(CuentaPtr cuenta, int saldo){
    cuenta->saldo = saldo;
}

int getLimiteCredito(CuentaPtr cuenta){
    return cuenta->limiteCredito;
}

void setLimiteCredito(CuentaPtr cuenta, int limiteCredito){
    cuenta->limiteCredito = limiteCredito;
}

PtrPila getPilaMovimientos(CuentaPtr cuenta){
    return cuenta->pilaMovimientos;
}

void setPilaMovimientos(CuentaPtr cuenta, PtrPila pilaMovimientos){
    cuenta->pilaMovimientos = pilaMovimientos;
}

PtrCola getColaPagos(CuentaPtr cuenta){
    return cuenta->colaPagos;
}

void setColaPagos(CuentaPtr cuenta, PtrCola colaPagos){
    cuenta->colaPagos = colaPagos;
}
