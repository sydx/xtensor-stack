# This Makefile compiles the CBLAS routines
#
include Makefile.in

default : all

FORTRAN_SOURCE_FILES = $(wildcard *.f)
C_SOURCE_FILES = $(wildcard *.c)

FORTRAN_ASSEMBLY_FILES_NOUNDERSCORING = $(patsubst %.f,%_nu.s,$(FORTRAN_SOURCE_FILES))
FORTRAN_ASSEMBLY_FILES_WITHUNDERSCORING = $(patsubst %.f,%_wu.s,$(FORTRAN_SOURCE_FILES))
C_ASSEMBLY_FILES = $(patsubst %.c,%_c.s,$(C_SOURCE_FILES))

FORTRAN_OBJECT_FILES_NOUNDERSCORING = $(patsubst %.f,%_nu.o,$(FORTRAN_SOURCE_FILES))
FORTRAN_OBJECT_FILES_WITHUNDERSCORING = $(patsubst %.f,%_wu.o,$(FORTRAN_SOURCE_FILES))
C_OBJECT_FILES = $(patsubst %.c,%_c.o,$(C_SOURCE_FILES))

FC_NOUNDERSCORING = -fno-underscoring
FC_WITHUNDERSCORING = 

CBLAS_NU = ../cblas_nu.lib
CBLAS_WU = ../cblas_wu.lib

all : $(CBLAS_NU) $(CBLAS_WU)

$(CBLAS_NU) : $(FORTRAN_OBJECT_FILES_NOUNDERSCORING) $(C_OBJECT_FILES)
	ar crs $(CBLAS_NU) $(FORTRAN_OBJECT_FILES_NOUNDERSCORING) $(C_OBJECT_FILES)
	#ranlib $(CBLAS_NU)

$(CBLAS_WU) : $(FORTRAN_OBJECT_FILES_WITHUNDERSCORING) $(C_OBJECT_FILES)
	ar crs $(CBLAS_WU) $(FORTRAN_OBJECT_FILES_WITHUNDERSCORING) $(C_OBJECT_FILES)
	#ranlib $(CBLAS_WU)

%nu.o : %_nu.s
	$(CC) -lgfortran -lstdc++ -c -o $@ $<

%_wu.o : %_wu.s
	$(CC) -lgfortran -lstdc++ -c -o $@ $<

%_c.o : %_c.s
	$(CC) -lgfortran -lstdc++ -c -o $@ $<

%_nu.s : %.f
	$(FC) $(FCFLAGS) $(FC_NOUNDERSCORING) -S -o $@ $<

%_wu.s : %.f
	$(FC) $(FCFLAGS) $(FC_WITHUNDERSCORING) -S -o $@ $<

%_c.s : %.c
	$(CC) $(CFLAGS) -S -o $@ $<

clean :
	rm -f $(FORTRAN_ASSEMBLY_FILES_NOUNDERSCORING)
	rm -f $(FORTRAN_ASSEMBLY_FILE_WITHUNDERSCORING)
	rm -f $(C_ASSEMBLY_FILES)
	rm -f $(FORTRAN_OBJECT_FILES_NOUNDERSCORING)
	rm -f $(FORTRAN_OBJECT_FILES_WITHUNDERSCORING)
	rm -f $(C_OBJECT_FILES)
	rm -f $(CBLAS_NU)
	rm -f $(CBLAS_WU)
