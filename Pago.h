#ifndef PAGO_H_INCLUDED
#define PAGO_H_INCLUDED

typedef struct Pago{
    int idCuenta;
    int monto;
}Pago;

typedef Pago* PagoPtr;

// Operaci�n de creaci�n (Constructor)
// Precondiciones: pago no debe haberse creado
// Postcondiciones: se crea un pago con idCuenta, monto y empresa
// Par�metros:
// idCuenta: entero representando el id de la cuenta
// monto: entero representando el monto
// empresa: char representando la empresa
// Devuelve un puntero a la estructura Pago en memoria din�mica
PagoPtr crearPago(int idCuenta, int monto);

// Operaci�n de destrucci�n (Destructor)
// Precondiciones: se debe haber creado pago con crearPago
// Postcondiciones: se destruye pago y se libera la memoria que ocupaban
// Par�metros:
// pago: TDAPago a destruir
// Devuelve NULL
PagoPtr destruirPago(PagoPtr pago);

// Operaci�n de asignaci�n de monto del pago
// Precondicion: pago debe haberse creado
// Postcondici�n: pago cambia con el nuevo valor de monto
// Par�metros:
// pago: TDAPago al que se asignara el nuevo valor de monto
// monto: entero representando el nuevo valor de monto
// No devuelve valor.
void setMontoPago(PagoPtr pago, int monto);

// Operaci�n de obtenci�n del monto del pago
// Precondicion: pago debe haberse creado
// Postcondici�n: se obtiene el monto del pago
// Par�metros:
// pago: TDAPago del que se obtiene el monto
// Devuelve un entero representando el monto del pago
int getMontoPago(PagoPtr pago);

#endif // PAGO_H_INCLUDED
