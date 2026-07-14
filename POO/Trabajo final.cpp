
//Cajero Automático con Herencia
//Hecho por: Daniel Felipe Hernández García 
//Código: 20251578005
#include <iostream>
#include <fstream>
using namespace std;

// ==================== CLASE BASE: BANCO ====================
class Banco {
protected:
    char nombre[50];
    int codigoBanco;
    char direccion[100];
    char sucursal[50];

public:
    Banco() {
        int i;
        for(i = 0; i < 50; i++) nombre[i] = '\0';
        for(i = 0; i < 100; i++) direccion[i] = '\0';
        for(i = 0; i < 50; i++) sucursal[i] = '\0';
        
        char temp1[] = "Banco Nacional";
        for(i = 0; temp1[i] != '\0'; i++) nombre[i] = temp1[i];
        
        codigoBanco = 1001;
        
        char temp2[] = "Calle 100 # 50-25";
        for(i = 0; temp2[i] != '\0'; i++) direccion[i] = temp2[i];
        
        char temp3[] = "Sucursal Principal";
        for(i = 0; temp3[i] != '\0'; i++) sucursal[i] = temp3[i];
    }
    
    void EntradaBanco();
    void SalidaBanco();
};

void Banco::EntradaBanco() {
    cout << "\n=== DATOS DEL BANCO ===" << endl;
    cout << "Nombre del Banco: ";
    cin.getline(nombre, 50);
    cout << "Codigo del Banco: ";
    cin >> codigoBanco;
    cin.ignore();
    cout << "Direccion: ";
    cin.getline(direccion, 100);
    cout << "Sucursal: ";
    cin.getline(sucursal, 50);
}

void Banco::SalidaBanco() {
    cout << "\n--- Informacion del Banco ---" << endl;
    cout << "Banco: " << nombre << endl;
    cout << "Codigo: " << codigoBanco << endl;
    cout << "Direccion: " << direccion << endl;
    cout << "Sucursal: " << sucursal << endl;
}

// ==================== CLASE: CLIENTE ====================
class Cliente : public Banco {
protected:
    char nombreCliente[50];
    char cedula[20];
    char direccionCliente[100];
    char telefono[15];

public:
    Cliente() {
        int i;
        for(i = 0; i < 50; i++) nombreCliente[i] = '\0';
        for(i = 0; i < 20; i++) cedula[i] = '\0';
        for(i = 0; i < 100; i++) direccionCliente[i] = '\0';
        for(i = 0; i < 15; i++) telefono[i] = '\0';
    }
    
    void EntradaCliente();
    void SalidaCliente();
};

void Cliente::EntradaCliente() {
    cout << "\n=== DATOS DEL CLIENTE ===" << endl;
    cout << "Nombre completo: ";
    cin.getline(nombreCliente, 50);
    cout << "Cedula: ";
    cin.getline(cedula, 20);
    cout << "Direccion: ";
    cin.getline(direccionCliente, 100);
    cout << "Telefono: ";
    cin.getline(telefono, 15);
}

void Cliente::SalidaCliente() {
    cout << "\n--- Datos del Cliente ---" << endl;
    cout << "Nombre: " << nombreCliente << endl;
    cout << "Cedula: " << cedula << endl;
    cout << "Direccion: " << direccionCliente << endl;
    cout << "Telefono: " << telefono << endl;
}

// ==================== CLASE: CUENTA ====================
class Cuenta : public Cliente {
protected:
    char numeroCuenta[20];
    double saldo;
    double interes;
    char clave[10];
    char tipoCuenta[15];

public:
    Cuenta() {
        int i;
        for(i = 0; i < 20; i++) numeroCuenta[i] = '\0';
        for(i = 0; i < 10; i++) clave[i] = '\0';
        for(i = 0; i < 15; i++) tipoCuenta[i] = '\0';
        
        saldo = 0.0;
        interes = 0.0;
        
        char temp1[] = "1234";
        for(i = 0; temp1[i] != '\0'; i++) clave[i] = temp1[i];
        
        char temp2[] = "Ahorros";
        for(i = 0; temp2[i] != '\0'; i++) tipoCuenta[i] = temp2[i];
    }
    
    void EntradaCuenta();
    void SalidaCuenta();
    bool ValidarClave(char* claveIngresada);
    double ObtenerSaldo() { return saldo; }
    void ActualizarSaldo(double nuevoSaldo) { saldo = nuevoSaldo; }
};

void Cuenta::EntradaCuenta() {
    cout << "\n=== DATOS DE LA CUENTA ===" << endl;
    cout << "Numero de cuenta: ";
    cin.getline(numeroCuenta, 20);
    cout << "Saldo inicial: ";
    cin >> saldo;
    cout << "Tasa de interes (%): ";
    cin >> interes;
    cout << "Clave (4 digitos): ";
    cin >> clave;
    cout << "Tipo de cuenta (Ahorros/Corriente): ";
    cin.ignore();
    cin.getline(tipoCuenta, 15);
}

void Cuenta::SalidaCuenta() {
    cout << "\n--- Datos de la Cuenta ---" << endl;
    cout << "Numero: " << numeroCuenta << endl;
    cout << "Tipo: " << tipoCuenta << endl;
    cout << "Saldo: $" << saldo << endl;
    cout << "Interes: " << interes << "%" << endl;
}

bool Cuenta::ValidarClave(char* claveIngresada) {
    int i = 0;
    while(clave[i] != '\0' && claveIngresada[i] != '\0') {
        if(clave[i] != claveIngresada[i]) return false;
        i++;
    }
    return (clave[i] == '\0' && claveIngresada[i] == '\0');
}

// ==================== CLASE: TRANSACCION ====================
class Transaccion : public Cuenta {
protected:
    double valor;
    char fecha[20];
    char tipoTransaccion[20];
    double saldoActual;
    double impuesto4x1000;

public:
    Transaccion() {
        int i;
        for(i = 0; i < 20; i++) fecha[i] = '\0';
        for(i = 0; i < 20; i++) tipoTransaccion[i] = '\0';
        
        valor = 0.0;
        saldoActual = 0.0;
        impuesto4x1000 = 0.0;
    }
    
    void ObtenerFechaHora();
    void Consignar();
    void Retirar();
    void Consultar();
    void Transferir();
    void GenerarRecibo();
    void GenerarHistorico();
};

void Transaccion::ObtenerFechaHora() {
    char temp[] = "2025-12-10 14:30:00";
    int i;
    for(i = 0; temp[i] != '\0'; i++) {
        fecha[i] = temp[i];
    }
    fecha[i] = '\0';
}

void Transaccion::Consignar() {
    cout << "\n*** CONSIGNACION ***" << endl;
    cout << "Valor a consignar: $";
    cin >> valor;
    
    saldoActual = ObtenerSaldo();
    saldoActual += valor;
    ActualizarSaldo(saldoActual);
    
    char temp[] = "Consignacion";
    int i;
    for(i = 0; temp[i] != '\0'; i++) tipoTransaccion[i] = temp[i];
    tipoTransaccion[i] = '\0';
    
    impuesto4x1000 = 0.0;
    
    ObtenerFechaHora();
    GenerarRecibo();
    GenerarHistorico();
    
    cout << "\nConsignacion exitosa!" << endl;
    cout << "Nuevo saldo: $" << saldoActual << endl;
}

void Transaccion::Retirar() {
    cout << "\n*** RETIRO ***" << endl;
    cout << "Valor a retirar: $";
    cin >> valor;
    
    impuesto4x1000 = valor * 0.004;
    double totalRetiro = valor + impuesto4x1000;
    
    saldoActual = ObtenerSaldo();
    
    if (saldoActual >= totalRetiro) {
        saldoActual -= totalRetiro;
        ActualizarSaldo(saldoActual);
        
        char temp[] = "Retiro";
        int i;
        for(i = 0; temp[i] != '\0'; i++) tipoTransaccion[i] = temp[i];
        tipoTransaccion[i] = '\0';
        
        ObtenerFechaHora();
        GenerarRecibo();
        GenerarHistorico();
        
        cout << "\nRetiro exitoso!" << endl;
        cout << "Valor retirado: $" << valor << endl;
        cout << "Impuesto 4x1000: $" << impuesto4x1000 << endl;
        cout << "Nuevo saldo: $" << saldoActual << endl;
    } else {
        cout << "\nSaldo insuficiente!" << endl;
        cout << "Saldo disponible: $" << saldoActual << endl;
    }
}

void Transaccion::Consultar() {
    cout << "\n*** CONSULTA DE SALDO ***" << endl;
    SalidaBanco();
    SalidaCliente();
    SalidaCuenta();
    
    char temp[] = "Consulta";
    int i;
    for(i = 0; temp[i] != '\0'; i++) tipoTransaccion[i] = temp[i];
    tipoTransaccion[i] = '\0';
    
    valor = 0.0;
    impuesto4x1000 = 0.0;
    saldoActual = ObtenerSaldo();
    
    ObtenerFechaHora();
    GenerarHistorico();
}

void Transaccion::Transferir() {
    char cuentaDestino[20];
    cout << "\n*** TRANSFERENCIA ***" << endl;
    cout << "Cuenta destino: ";
    cin.ignore();
    cin.getline(cuentaDestino, 20);
    cout << "Valor a transferir: $";
    cin >> valor;
    
    impuesto4x1000 = valor * 0.004;
    double totalTransferencia = valor + impuesto4x1000;
    
    saldoActual = ObtenerSaldo();
    
    if (saldoActual >= totalTransferencia) {
        saldoActual -= totalTransferencia;
        ActualizarSaldo(saldoActual);
        
        char temp[] = "Transferencia";
        int i;
        for(i = 0; temp[i] != '\0'; i++) tipoTransaccion[i] = temp[i];
        tipoTransaccion[i] = '\0';
        
        ObtenerFechaHora();
        GenerarRecibo();
        GenerarHistorico();
        
        cout << "\nTransferencia exitosa a cuenta: " << cuentaDestino << endl;
        cout << "Valor transferido: $" << valor << endl;
        cout << "Impuesto 4x1000: $" << impuesto4x1000 << endl;
        cout << "Nuevo saldo: $" << saldoActual << endl;
    } else {
        cout << "\nSaldo insuficiente!" << endl;
    }
}

void Transaccion::GenerarRecibo() {
    ofstream archivo("recibo.txt");
    
    if (archivo.is_open()) {
        archivo << "========================================" << endl;
        archivo << "         RECIBO DE TRANSACCION          " << endl;
        archivo << "========================================" << endl;
        archivo << "Banco: " << nombre << endl;
        archivo << "Sucursal: " << sucursal << endl;
        archivo << "Fecha: " << fecha << endl;
        archivo << "----------------------------------------" << endl;
        archivo << "Cliente: " << nombreCliente << endl;
        archivo << "Cedula: " << cedula << endl;
        archivo << "Cuenta: " << numeroCuenta << endl;
        archivo << "Tipo: " << tipoCuenta << endl;
        archivo << "----------------------------------------" << endl;
        archivo << "Tipo Transaccion: " << tipoTransaccion << endl;
        archivo << "Valor: $" << valor << endl;
        
        if (impuesto4x1000 > 0) {
            archivo << "Impuesto 4x1000: $" << impuesto4x1000 << endl;
        }
        
        archivo << "Saldo Actual: $" << saldoActual << endl;
        archivo << "========================================" << endl;
        
        archivo.close();
        cout << "\nRecibo generado: recibo.txt" << endl;
    }
}

void Transaccion::GenerarHistorico() {
    ofstream archivo("historico.txt", ios::app);
    
    if (archivo.is_open()) {
        archivo << fecha << " | " 
                << tipoTransaccion << " | "
                << "Cuenta: " << numeroCuenta << " | "
                << "Valor: $" << valor << " | "
                << "4x1000: $" << impuesto4x1000 << " | "
                << "Saldo: $" << saldoActual << endl;
        archivo.close();
    }
}

// ==================== CLASE: EXTRACTO ====================
class Extracto : public Transaccion {
private:
    char periodo[20];
    double saldoInicial;
    double totalConsignaciones;
    double totalRetiros;

public:
    Extracto() {
        int i;
        for(i = 0; i < 20; i++) periodo[i] = '\0';
        saldoInicial = 0.0;
        totalConsignaciones = 0.0;
        totalRetiros = 0.0;
    }
    
    void GenerarExtracto();
    void MostrarExtracto();
};

void Extracto::GenerarExtracto() {
    cout << "\n=== GENERACION DE EXTRACTO ===" << endl;
    cout << "Periodo (ej. Diciembre 2025): ";
    cin.ignore();
    cin.getline(periodo, 20);
    
    cout << "Saldo inicial del periodo: $";
    cin >> saldoInicial;
    
    cout << "Total consignaciones: $";
    cin >> totalConsignaciones;
    
    cout << "Total retiros: $";
    cin >> totalRetiros;
    
    ofstream archivo("extracto.txt");
    
    if (archivo.is_open()) {
        archivo << "============================================" << endl;
        archivo << "            EXTRACTO BANCARIO               " << endl;
        archivo << "============================================" << endl;
        archivo << nombre << endl;
        archivo << "Codigo Banco: " << codigoBanco << endl;
        archivo << direccion << endl;
        archivo << "Sucursal: " << sucursal << endl;
        archivo << "============================================" << endl;
        archivo << "CLIENTE: " << nombreCliente << endl;
        archivo << "CEDULA: " << cedula << endl;
        archivo << "DIRECCION: " << direccionCliente << endl;
        archivo << "TELEFONO: " << telefono << endl;
        archivo << "============================================" << endl;
        archivo << "CUENTA No: " << numeroCuenta << endl;
        archivo << "TIPO: " << tipoCuenta << endl;
        archivo << "PERIODO: " << periodo << endl;
        archivo << "============================================" << endl;
        archivo << "RESUMEN DE MOVIMIENTOS:" << endl;
        archivo << "--------------------------------------------" << endl;
        archivo << "Saldo Inicial:        $" << saldoInicial << endl;
        archivo << "Total Consignaciones: $" << totalConsignaciones << endl;
        archivo << "Total Retiros:        $" << totalRetiros << endl;
        archivo << "--------------------------------------------" << endl;
        archivo << "Saldo Final:          $" << ObtenerSaldo() << endl;
        archivo << "============================================" << endl;
        archivo << "Interes Mensual: " << interes << "%" << endl;
        archivo << "============================================" << endl;
        
        archivo << "\nDETALLE DE TRANSACCIONES:" << endl;
        archivo << "--------------------------------------------" << endl;
        
        ifstream historico("historico.txt");
        if (historico.is_open()) {
            char linea[256];
            while (historico.getline(linea, 256)) {
                archivo << linea << endl;
            }
            historico.close();
        }
        
        archivo << "============================================" << endl;
        
        archivo.close();
        cout << "\nExtracto generado exitosamente: extracto.txt" << endl;
    }
}

void Extracto::MostrarExtracto() {
    ifstream archivo("extracto.txt");
    
    if (archivo.is_open()) {
        char linea[256];
        cout << "\n";
        while (archivo.getline(linea, 256)) {
            cout << linea << endl;
        }
        archivo.close();
    } else {
        cout << "No se pudo abrir el extracto. Genere uno primero." << endl;
    }
}

// ==================== FUNCION PRINCIPAL ====================
int main() {
    Extracto cajero;
    char claveIngresada[10];
    int opcion;
    bool sesionIniciada = false;
    
    cout << "======================================" << endl;
    cout << "   SISTEMA CAJERO AUTOMATICO         " << endl;
    cout << "======================================" << endl;
    
    cajero.EntradaBanco();
    cajero.EntradaCliente();
    cajero.EntradaCuenta();
    
    cout << "\n--- INICIO DE SESION ---" << endl;
    cout << "Ingrese su clave: ";
    cin >> claveIngresada;
    
    if (!cajero.ValidarClave(claveIngresada)) {
        cout << "\nClave incorrecta. Acceso denegado." << endl;
        return 1;
    }
    
    cout << "\n¡Bienvenido al cajero automatico!" << endl;
    sesionIniciada = true;
    
    do {
        cout << "\n======================================" << endl;
        cout << "           MENU PRINCIPAL             " << endl;
        cout << "======================================" << endl;
        cout << "1. Consignar" << endl;
        cout << "2. Retirar" << endl;
        cout << "3. Consultar Saldo" << endl;
        cout << "4. Transferir" << endl;
        cout << "5. Generar Extracto" << endl;
        cout << "6. Mostrar Extracto" << endl;
        cout << "7. Salir" << endl;
        cout << "======================================" << endl;
        cout << "Opcion: ";
        cin >> opcion;
        
        switch (opcion) {
            case 1:
                cajero.Consignar();
                break;
            case 2:
                cajero.Retirar();
                break;
            case 3:
                cajero.Consultar();
                break;
            case 4:
                cajero.Transferir();
                break;
            case 5:
                cajero.GenerarExtracto();
                break;
            case 6:
                cajero.MostrarExtracto();
                break;
            case 7:
                cout << "\nGracias por usar nuestro cajero automatico." << endl;
                cout << "¡Hasta pronto!" << endl;
                break;
            default:
                cout << "\nOpcion invalida. Intente nuevamente." << endl;
        }
        
    } while (opcion != 7);
    
    return 0;
}