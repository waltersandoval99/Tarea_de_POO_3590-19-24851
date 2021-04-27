#include <mysql.h>
#include <string>
#include <iostream>
using namespace std;
int q_estado;
int main()
{
	MYSQL* conectar;
	conectar = mysql_init(0);
	conectar = mysql_real_connect(conectar, "localhost", "usrempresa", "@49215664T", "tarea_poo", 3306, NULL, 0);
	if (conectar) {
		cout << "Ingreso Exitoso..." << endl;

		string 	idClientes, Nit, Nombres, Apellidos, Direccion, Telefono, Fecha_Nacimiento;
		
		cout << "Ingrese Nombre: ";
		cin >> Nombres;
		cout << "Ingrese Apellidos: ";
		cin >> Apellidos;
		cout << "Ingrese Direccion: ";
		cin >> Direccion;
		cout << "Ingrese Telefono: ";
		cin >> Telefono;
		cout << "Ingrese Nit: ";
		cin >> Nit;
		cout << "Ingrese idClientes: ";
		cin >> idClientes;
		cout << "Ingrese Fecha_Nacimiento: ";
		cin >> Fecha_Nacimiento;
		cout << "Ingrese idPuestos: ";
		
		string insert = "insert into clientes (idClientes, Nit, Nombres, Apellidos, Direccion, Telefono, Fecha_Nacimiento)
			values('" + Nombres + "', '" + Apellidos + "', '" + Direccion + "', '" + Telefono + "', '" + Nit + "', '" + Fecha_Nacimiento + "', '"idClientes"';)";
		const char* i = insert.c_str();
		q_estado = mysql_query(conectar, i);
		if (!q_estado) {
			cout << "Ingreso Exitoso..." << endl;
		}
		else {
			cout << "Ingreso " << endl;
		}

		string consulta = "select * from clietes.idClientes";
		const char* c = consulta.c_str();
		q_estado = mysql_query(conectar, c);
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		if (!q_estado) {
			resultado = mysql_store_result(conectar);

			while (fila = mysql_fetch_row(resultado)) {
				cout << fila[0] << "," << fila[1] << "," << fila[2] << "," << fila[3] << "," << fila[4] << "," << fila[5] << "," << fila[6] << "," << fila[7]<< endl;
			}
		}
		else {
			cout << "**** Error ****" << endl;
		}

		string e;
		cout << "Ingrese el idClientes a eliminar: ";
		cin >> e;
		string eliminar = "delete from clientes.clientes where idClientes= '" + e + "'";
		const char* f = eliminar.c_str();
		q_estado = mysql_query(conectar, f);

		if (!q_estado) {
			cout << "Eliminacio Exitosa" << endl;
		}
		else {
			cout << " Eliminacio no Exitosa " << endl;
		}

		string a;
		string b;
		string h;
		string j;
		string k;
		string m;
		string g;

		cout << "Ingrese el ID a Editar: ";
		cin >> g;
		cout << "Ingrese nuevo Nombre: ";
		cin >> a;
		cout << "Ingrese nuevo Apellido: ";
		cin >> b;
		cout << "Ingrese nueva Direccion: ";
		cin >> h;
		cout << "Ingrese nuevo Telefono: ";
		cin >> j;
		cout << "Ingrese nuevo Nit: ";
		cin >> k;
		cout << "Ingrese nueva Fecha de Nacimiento: ";
		cin >> m;
		
		string editar = "update clientes set Nombres= '" + a + "', Apellidos= '" + b + "', Direccion= '" + h + "', Telefono= '" + j + "', Nit= '" + k + "', Fecha_Nacimiento= '" + m + "', where idClientes= '" + g + "'";
		const char* c = editar.c_str();
		q_estado = mysql_query(conectar, c);

		if (!q_estado) {
			cout << " Edicion Exitosa " << endl;
		}
		else {
			cout << " Edicion Exitosa " << endl;
		}

	}
	else {
		cout << "Error en la Operación..." << endl;
	}
	system("pause");
	return 0;
}