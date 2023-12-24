FC = gfortran

# Problem: If we attempt to compile and assemble in one go, gcc, called by gfortran
# to assemble the code, will produce the following error message:
#     Cannot create temporary file in C:\Windows\: Permission denied
# Our workaround is to split the process into compilation and a separate assembly
# step. -S means do not assemble.
FCFLAGS           += -g -fimplicit-none -S
# For verbose output (including underlying command lines) append -v

FC_NOUNDERSCORING  = -fno-underscoring

# SOURCE_FILES = $(filter-out ilaenv.f, $(wildcard *.f))
SOURCE_FILES = $(wildcard *.f)

ASSEMBLY_FILES_NOUNDERSCORING = $(filter-out xerbla_nu.s, $(patsubst %.f,%_nu.s,$(SOURCE_FILES)))
ASSEMBLY_FILES_WITHUNDERSCORING = $(patsubst %.f,%_wu.s,$(SOURCE_FILES))

OBJECT_FILES_NOUNDERSCORING   =  $(filter-out xerbla_nu.o, $(patsubst %.f,%_nu.o,$(SOURCE_FILES)))
OBJECT_FILES_WITHUNDERSCORING =  $(patsubst %.f,%_wu.o,$(SOURCE_FILES))


REFLAPACK_NU = ../libreflapack_nu.lib
REFLAPACK_WU = ../libreflapack_wu.lib

all : $(REFLAPACK_NU) $(REFLAPACK_WU)

$(REFLAPACK_NU) : $(OBJECT_FILES_NOUNDERSCORING)
	ar crs $(REFLAPACK_NU) $(OBJECT_FILES_NOUNDERSCORING)
	#ranlib $(REFLAPACK_NU)

$(REFLAPACK_WU) : $(OBJECT_FILES_WITHUNDERSCORING)
	ar crs $(REFLAPACK_WU) $(OBJECT_FILES_WITHUNDERSCORING)
	#ranlib $(REFLAPACK_WU)

%_nu.o : %_nu.s
	gcc -lgfortran -lstdc++ -c -o $@ $<

%_wu.o : %_wu.s
	gcc -lgfortran -lstdc++ -c -o $@ $<

%_nu.s : %.f
	$(FC) $(FCFLAGS) $(FC_NOUNDERSCORING) -c -o $@ $<

%_wu.s : %.f
	$(FC) $(FCFLAGS) $(FC_WITHUNDERSCORING) -c -o $@ $<

clean :
	rm -f $(ASSEMBLY_FILES_NOUNDERSCORING)
	rm -f $(ASSEMBLY_FILES_WITHUNDERSCORING)
	rm -f $(OBJECT_FILES_NOUNDERSCORING)
	rm -f $(OBJECT_FILES_WITHUNDERSCORING)
	rm -f $(REFLAPACK_NU)
	rm -f $(REFLAPACK_WU)
