#ifndef PAGO_H_INCLUDED
#define PAGO_H_INCLUDED

typedef struct Pago{
    int idCuenta;
    int monto;
}Pago;

typedef Pago* PagoPtr;

// Operación de creación (Constructor)
// Precondiciones: pago no debe haberse creado
// Postcondiciones: se crea un pago con idCuenta, monto y empresa
// Parámetros:
// idCuenta: entero representando el id de la cuenta
// monto: entero representando el monto
// empresa: char representando la empresa
// Devuelve un puntero a la estructura Pago en memoria dinámica
PagoPtr crearPago(int idCuenta, int monto);

// Operación de destrucción (Destructor)
// Precondiciones: se debe haber creado pago con crearPago
// Postcondiciones: se destruye pago y se libera la memoria que ocupaban
// Parámetros:
// pago: TDAPago a destruir
// Devuelve NULL
PagoPtr destruirPago(PagoPtr pago);

// Operación de asignación de monto del pago
// Precondicion: pago debe haberse creado
// Postcondición: pago cambia con el nuevo valor de monto
// Parámetros:
// pago: TDAPago al que se asignara el nuevo valor de monto
// monto: entero representando el nuevo valor de monto
// No devuelve valor.
void setMontoPago(PagoPtr pago, int monto);

// Operación de obtención del monto del pago
// Precondicion: pago debe haberse creado
// Postcondición: se obtiene el monto del pago
// Parámetros:
// pago: TDAPago del que se obtiene el monto
// Devuelve un entero representando el monto del pago
int getMontoPago(PagoPtr pago);

#endif // PAGO_H_INCLUDED
