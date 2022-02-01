#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=mkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/P0.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/P0.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS
SUB_IMAGE_ADDRESS_COMMAND=--image-address $(SUB_IMAGE_ADDRESS)
else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=advolts.c delay.c hexdec.c init_ADC.c init_DMAC0.c init_timer1.c isr_ADC.c isr_DMAC0.c isr_timer1.c lcd.c main_rtc.c traps.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/advolts.o ${OBJECTDIR}/delay.o ${OBJECTDIR}/hexdec.o ${OBJECTDIR}/init_ADC.o ${OBJECTDIR}/init_DMAC0.o ${OBJECTDIR}/init_timer1.o ${OBJECTDIR}/isr_ADC.o ${OBJECTDIR}/isr_DMAC0.o ${OBJECTDIR}/isr_timer1.o ${OBJECTDIR}/lcd.o ${OBJECTDIR}/main_rtc.o ${OBJECTDIR}/traps.o
POSSIBLE_DEPFILES=${OBJECTDIR}/advolts.o.d ${OBJECTDIR}/delay.o.d ${OBJECTDIR}/hexdec.o.d ${OBJECTDIR}/init_ADC.o.d ${OBJECTDIR}/init_DMAC0.o.d ${OBJECTDIR}/init_timer1.o.d ${OBJECTDIR}/isr_ADC.o.d ${OBJECTDIR}/isr_DMAC0.o.d ${OBJECTDIR}/isr_timer1.o.d ${OBJECTDIR}/lcd.o.d ${OBJECTDIR}/main_rtc.o.d ${OBJECTDIR}/traps.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/advolts.o ${OBJECTDIR}/delay.o ${OBJECTDIR}/hexdec.o ${OBJECTDIR}/init_ADC.o ${OBJECTDIR}/init_DMAC0.o ${OBJECTDIR}/init_timer1.o ${OBJECTDIR}/isr_ADC.o ${OBJECTDIR}/isr_DMAC0.o ${OBJECTDIR}/isr_timer1.o ${OBJECTDIR}/lcd.o ${OBJECTDIR}/main_rtc.o ${OBJECTDIR}/traps.o

# Source Files
SOURCEFILES=advolts.c delay.c hexdec.c init_ADC.c init_DMAC0.c init_timer1.c isr_ADC.c isr_DMAC0.c isr_timer1.c lcd.c main_rtc.c traps.c



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/P0.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=24HJ256GP610A
MP_LINKER_FILE_OPTION=,--script=p24HJ256GP610A.gld
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/advolts.o: advolts.c  .generated_files/flags/default/48361e661397e63429a7751d1640f5b54cf21bb1 .generated_files/flags/default/4a52a4176c68d659fc519dd2cee25e907f150a31
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/advolts.o.d 
	@${RM} ${OBJECTDIR}/advolts.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  advolts.c  -o ${OBJECTDIR}/advolts.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/advolts.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/delay.o: delay.c  .generated_files/flags/default/a075b4dd1a48a5f845348c4161e37a88c3e47aec .generated_files/flags/default/4a52a4176c68d659fc519dd2cee25e907f150a31
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/delay.o.d 
	@${RM} ${OBJECTDIR}/delay.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  delay.c  -o ${OBJECTDIR}/delay.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/delay.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/hexdec.o: hexdec.c  .generated_files/flags/default/bf917bec1a39430cc47d9e9cdadf5a94eac01752 .generated_files/flags/default/4a52a4176c68d659fc519dd2cee25e907f150a31
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/hexdec.o.d 
	@${RM} ${OBJECTDIR}/hexdec.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  hexdec.c  -o ${OBJECTDIR}/hexdec.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/hexdec.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/init_ADC.o: init_ADC.c  .generated_files/flags/default/f8658fe26d6cfc152888284bb0cc51c82368b532 .generated_files/flags/default/4a52a4176c68d659fc519dd2cee25e907f150a31
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/init_ADC.o.d 
	@${RM} ${OBJECTDIR}/init_ADC.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  init_ADC.c  -o ${OBJECTDIR}/init_ADC.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/init_ADC.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/init_DMAC0.o: init_DMAC0.c  .generated_files/flags/default/bd8c462ceef4a716e70c78c6e7a0d917a3731384 .generated_files/flags/default/4a52a4176c68d659fc519dd2cee25e907f150a31
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/init_DMAC0.o.d 
	@${RM} ${OBJECTDIR}/init_DMAC0.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  init_DMAC0.c  -o ${OBJECTDIR}/init_DMAC0.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/init_DMAC0.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/init_timer1.o: init_timer1.c  .generated_files/flags/default/14bb9205f67a82e3614c74072a4ace7acabd6725 .generated_files/flags/default/4a52a4176c68d659fc519dd2cee25e907f150a31
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/init_timer1.o.d 
	@${RM} ${OBJECTDIR}/init_timer1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  init_timer1.c  -o ${OBJECTDIR}/init_timer1.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/init_timer1.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/isr_ADC.o: isr_ADC.c  .generated_files/flags/default/e9c7df208fb9bda048a736947afd91fa2fd915fa .generated_files/flags/default/4a52a4176c68d659fc519dd2cee25e907f150a31
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/isr_ADC.o.d 
	@${RM} ${OBJECTDIR}/isr_ADC.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  isr_ADC.c  -o ${OBJECTDIR}/isr_ADC.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/isr_ADC.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/isr_DMAC0.o: isr_DMAC0.c  .generated_files/flags/default/acbfbe963764350c15e0641177d2167338a70fbd .generated_files/flags/default/4a52a4176c68d659fc519dd2cee25e907f150a31
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/isr_DMAC0.o.d 
	@${RM} ${OBJECTDIR}/isr_DMAC0.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  isr_DMAC0.c  -o ${OBJECTDIR}/isr_DMAC0.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/isr_DMAC0.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/isr_timer1.o: isr_timer1.c  .generated_files/flags/default/816cc8894b061056aca44ddf444b3581a1034c8 .generated_files/flags/default/4a52a4176c68d659fc519dd2cee25e907f150a31
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/isr_timer1.o.d 
	@${RM} ${OBJECTDIR}/isr_timer1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  isr_timer1.c  -o ${OBJECTDIR}/isr_timer1.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/isr_timer1.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/lcd.o: lcd.c  .generated_files/flags/default/c92c2860c931526d346c434aa6d31aba94f05dcc .generated_files/flags/default/4a52a4176c68d659fc519dd2cee25e907f150a31
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/lcd.o.d 
	@${RM} ${OBJECTDIR}/lcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  lcd.c  -o ${OBJECTDIR}/lcd.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/lcd.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/main_rtc.o: main_rtc.c  .generated_files/flags/default/2d1cc83b4d340f6efdb56b6d83f0fde8a36b3bb8 .generated_files/flags/default/4a52a4176c68d659fc519dd2cee25e907f150a31
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main_rtc.o.d 
	@${RM} ${OBJECTDIR}/main_rtc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  main_rtc.c  -o ${OBJECTDIR}/main_rtc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/main_rtc.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/traps.o: traps.c  .generated_files/flags/default/8c28daadce357c1f7f7018a27a84022c557b0d50 .generated_files/flags/default/4a52a4176c68d659fc519dd2cee25e907f150a31
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/traps.o.d 
	@${RM} ${OBJECTDIR}/traps.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  traps.c  -o ${OBJECTDIR}/traps.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/traps.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
else
${OBJECTDIR}/advolts.o: advolts.c  .generated_files/flags/default/a6e558929d70387a882a386f53cf52761b73f7b4 .generated_files/flags/default/4a52a4176c68d659fc519dd2cee25e907f150a31
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/advolts.o.d 
	@${RM} ${OBJECTDIR}/advolts.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  advolts.c  -o ${OBJECTDIR}/advolts.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/advolts.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/delay.o: delay.c  .generated_files/flags/default/7418b5570da27660d7e5897375a280320cba8654 .generated_files/flags/default/4a52a4176c68d659fc519dd2cee25e907f150a31
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/delay.o.d 
	@${RM} ${OBJECTDIR}/delay.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  delay.c  -o ${OBJECTDIR}/delay.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/delay.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/hexdec.o: hexdec.c  .generated_files/flags/default/c1c75056b77d690fb461fbe49e50c3620ca4ea95 .generated_files/flags/default/4a52a4176c68d659fc519dd2cee25e907f150a31
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/hexdec.o.d 
	@${RM} ${OBJECTDIR}/hexdec.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  hexdec.c  -o ${OBJECTDIR}/hexdec.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/hexdec.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/init_ADC.o: init_ADC.c  .generated_files/flags/default/17d61b408d225eb99608bf92ed5b179c9f461cb5 .generated_files/flags/default/4a52a4176c68d659fc519dd2cee25e907f150a31
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/init_ADC.o.d 
	@${RM} ${OBJECTDIR}/init_ADC.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  init_ADC.c  -o ${OBJECTDIR}/init_ADC.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/init_ADC.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/init_DMAC0.o: init_DMAC0.c  .generated_files/flags/default/f6c234565aaa854607ff5fc466636e32f138751d .generated_files/flags/default/4a52a4176c68d659fc519dd2cee25e907f150a31
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/init_DMAC0.o.d 
	@${RM} ${OBJECTDIR}/init_DMAC0.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  init_DMAC0.c  -o ${OBJECTDIR}/init_DMAC0.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/init_DMAC0.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/init_timer1.o: init_timer1.c  .generated_files/flags/default/2f365e1ff599e5f854f1cac011e06b4287233136 .generated_files/flags/default/4a52a4176c68d659fc519dd2cee25e907f150a31
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/init_timer1.o.d 
	@${RM} ${OBJECTDIR}/init_timer1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  init_timer1.c  -o ${OBJECTDIR}/init_timer1.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/init_timer1.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/isr_ADC.o: isr_ADC.c  .generated_files/flags/default/cfa605b5d0873720a2f2dd08d5682b358b56c59f .generated_files/flags/default/4a52a4176c68d659fc519dd2cee25e907f150a31
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/isr_ADC.o.d 
	@${RM} ${OBJECTDIR}/isr_ADC.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  isr_ADC.c  -o ${OBJECTDIR}/isr_ADC.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/isr_ADC.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/isr_DMAC0.o: isr_DMAC0.c  .generated_files/flags/default/203235b5a0f0ff0eec2eab6cb0d563387c9af061 .generated_files/flags/default/4a52a4176c68d659fc519dd2cee25e907f150a31
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/isr_DMAC0.o.d 
	@${RM} ${OBJECTDIR}/isr_DMAC0.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  isr_DMAC0.c  -o ${OBJECTDIR}/isr_DMAC0.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/isr_DMAC0.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/isr_timer1.o: isr_timer1.c  .generated_files/flags/default/1c66d91552797f9b33d5a65e8d4f45f236f2e46e .generated_files/flags/default/4a52a4176c68d659fc519dd2cee25e907f150a31
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/isr_timer1.o.d 
	@${RM} ${OBJECTDIR}/isr_timer1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  isr_timer1.c  -o ${OBJECTDIR}/isr_timer1.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/isr_timer1.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/lcd.o: lcd.c  .generated_files/flags/default/dae2d59e678404030b65b2eacb1cc8681a8288aa .generated_files/flags/default/4a52a4176c68d659fc519dd2cee25e907f150a31
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/lcd.o.d 
	@${RM} ${OBJECTDIR}/lcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  lcd.c  -o ${OBJECTDIR}/lcd.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/lcd.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/main_rtc.o: main_rtc.c  .generated_files/flags/default/40e860824a122c2855f66065aa7c7b25a7e278fe .generated_files/flags/default/4a52a4176c68d659fc519dd2cee25e907f150a31
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main_rtc.o.d 
	@${RM} ${OBJECTDIR}/main_rtc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  main_rtc.c  -o ${OBJECTDIR}/main_rtc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/main_rtc.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/traps.o: traps.c  .generated_files/flags/default/4e56a4ff78177fbdbfabba70c25f7b32752972e9 .generated_files/flags/default/4a52a4176c68d659fc519dd2cee25e907f150a31
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/traps.o.d 
	@${RM} ${OBJECTDIR}/traps.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  traps.c  -o ${OBJECTDIR}/traps.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/traps.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemblePreproc
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/P0.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o ${DISTDIR}/P0.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -D__DEBUG=__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)   -mreserve=data@0x800:0x81F -mreserve=data@0x820:0x821 -mreserve=data@0x822:0x823 -mreserve=data@0x824:0x825 -mreserve=data@0x826:0x84F   -Wl,,,--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D__DEBUG=__DEBUG,--defsym=__MPLAB_DEBUGGER_REAL_ICE=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,${DISTDIR}/memoryfile.xml$(MP_EXTRA_LD_POST)  -mdfp="${DFP_DIR}/xc16" 
	
else
${DISTDIR}/P0.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o ${DISTDIR}/P0.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -Wl,,,--defsym=__MPLAB_BUILD=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,${DISTDIR}/memoryfile.xml$(MP_EXTRA_LD_POST)  -mdfp="${DFP_DIR}/xc16" 
	${MP_CC_DIR}/xc16-bin2hex ${DISTDIR}/P0.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} -a  -omf=elf   -mdfp="${DFP_DIR}/xc16" 
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${OBJECTDIR}
	${RM} -r ${DISTDIR}

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell "${PATH_TO_IDE_BIN}"mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
