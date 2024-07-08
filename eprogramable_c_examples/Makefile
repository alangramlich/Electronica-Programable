
########################################################################
#Cátedra: Electrónica Programable
#FIUNER
#2018
#Autor/es:
#JMreta - jmreta@ingenieria.uner.edu.ar
#
#Revisión:
#17-02-18: Versión inicial
########################################################################
-include makefile.mk

RUTA_BIN = out/
COMPILADOR = gcc
OPCIONES_COMPILACION = -Wall
FUENTE = $(PROYECTO_ACTIVO)/src/main.c
RUTA_CABECERA = $(PROYECTO_ACTIVO)/inc

all: $(NOMBRE_EJECUTABLE)

$(NOMBRE_EJECUTABLE): $(FUENTE)
	$(COMPILADOR) $(OPCIONES_COMPILACION) -I$(RUTA_CABECERA) $(FUENTE) -o $(RUTA_BIN)$(NOMBRE_EJECUTABLE)
#	$(COMPILADOR) $(OPCIONES_COMPILACION) $(FUENTE) -o $(RUTA_BIN)$@

clean:

	rm -f $(RUTA_BIN)*.exe
info: 
	@echo "----------Info----------"
	@echo "Proyecto Activo: "$(PROYECTO_ACTIVO)
	@echo "Ejecutable:" $(NOMBRE_EJECUTABLE)
	@echo "Fuente: " $(FUENTE)
	@echo "Cabeceras:" $(RUTA_CABECERA)
	@echo "----------Info----------"
	
help: 
	@echo "Electrónica Programable"
	@echo "info: Informa Rutas de Fuentes y Nombre del Ejecutable"	
	@echo "clean: Borra los archivos .exe"
