//Meilyn García 9959-23-17838
Algoritmo Calificacion
	Definir nota1, nota2, notaA, nota3, suma, suma_total Como Entero;
	Escribir 'Ingrese la nota 1 (no mayor de 20):';
	Leer nota1;
	Mientras nota1>20 Hacer
		Escribir 'La nota 1 no puede ser mayor de 20. Ingrese nuevamente:';
		Leer nota1;
	FinMientras
	Escribir 'Ingrese la nota 2 (no mayor de 25):';
	Leer nota2;
	Mientras nota2>25 Hacer
		Escribir 'La nota 2 no puede ser mayor de 25. Ingrese nuevamente:';
		Leer nota2;
	FinMientras
	Escribir 'Ingrese la nota Zona (notaA) (no mayor de 20):';
	Leer notaA;
	Mientras notaA>20 Hacer
		Escribir 'La nota Zona (notaA) no puede ser mayor de 20. Ingrese nuevamente:';
		Leer notaA;
	FinMientras
	suma <- nota1+nota2+notaA;
	Si suma<26 Entonces
		Escribir 'Curso reprobado. La suma de las notas es menor que 26.';
	SiNo
		Escribir 'Ingrese la nota 3 (no mayor de 35):';
		Leer nota3;
		Mientras nota3>35 Hacer
			Escribir 'La nota 3 no puede ser mayor de 35. Ingrese nuevamente:';
			Leer nota3;
		FinMientras
		suma_total <- suma+nota3;
		Si suma_total>=61 Entonces
			Escribir 'Imprimir acta. El estudiante ha aprobado el curso.';
		SiNo
			Escribir 'Curso reprobado. La suma total de notas es menor que 61.';
		FinSi
	FinSi
FinAlgoritmo
