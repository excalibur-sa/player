GDesktopEnums-3.0.gir: GDesktopEnums_3_0_gir_list 
	@-echo Generating $@...
	$(PYTHON) $(G_IR_SCANNER)	\
	--verbose -no-libtool	\
	--namespace=GDesktopEnums	\
	--nsversion=3.0	\
		\
		\
		\
	--add-include-path=$(G_IR_INCLUDEDIR)	\
		\
		\
	--cflags-begin	\
	-I..\headers	\
	--cflags-end	\
	--header-only --identifier-prefix=GDesktop	\
	--filelist=GDesktopEnums_3_0_gir_list	\
	-o $@

GDesktopEnums-3.0.typelib: GDesktopEnums-3.0.gir
	@-echo Compiling $@...
	$(G_IR_COMPILER)	\
	--includedir=. --debug --verbose	\
	GDesktopEnums-3.0.gir	\
	-o $@

