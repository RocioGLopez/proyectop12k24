//Hecho por Gabriela Pinto García / 9959-23-1087

Algoritmo CRUD_aula
    Definir opcion Como entero
	
    // Bucle principal
    Repetir
        // Menú principal
        Escribir "**************************"
        Escribir "*       Menu Aulas       *"
        Escribir "**************************"
        Escribir "1) Ingresar Aula "
        Escribir "2) Modificar Aula "
        Escribir "3) Borrar Aula"
        Escribir "4) Desplegar Aula "
        Escribir "5) Salir"
        Escribir "**************************"
        Escribir "* Seleccione [1/2/3/4/5] *"
        Escribir "**************************"
        Leer opcion
        
        Segun opcion hacer
				// Agregar sección
            Caso 1:
                Escribir "********** Agregar Aula **********"
                Escribir "Ingrese el codigo de la Aula: "
                Leer codigo
                Escribir "Ingrese el nombre de la Aula: "
                Leer nombre
                Escribir "Ingrese el estatus de la Aula: "
                Leer estatus
                Escribir "Aula guardada exitosamente..."
                
				// Modificar sección
            Caso 2:
                Escribir "********** Modificar Aula **********"
                Escribir "Ingrese el codigo de la Aula a modificar: "
                Leer codigo
                Escribir "Ingrese el nuevo nombre de la Aula: "
                Leer nombre
                Escribir "Ingrese el nuevo estatus de la Aula: "
                Leer estatus
                Escribir "Aula modificada correctamente..."
                
				// Borrar sección
            Caso 3:
                Escribir "********** Borrar Aula **********"
                Escribir "Ingrese el codigo de la Aula a borrar: "
                Leer codigo
                Escribir "Aula borrada correctamente..."
                
				// Desplegar secciones
            Caso 4:
                Escribir "********** Desplegar Aula **********"
                Escribir "Codigo de la Aula: ", codigo
                Escribir "Nombre de la Aula: ", nombre
                Escribir "Estatus de la Aula: ", estatus
                Escribir "----------------------------------------"
                
				// Salir
            Caso 5:
                Escribir "********** Salir **********"
                Escribir "Gracias por usar el sistema. ¡Hasta luego!"
                
            De Otro Modo:
                Escribir "Opcion invalida. Por favor, ingrese una opcion [1/2/3/4/5]"
        FinSegun
        
    Hasta Que opcion = 5
FinAlgoritmo

	