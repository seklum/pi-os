.global init_entry_point

.extern init
.extern irq_handler


init_entry_point:

	//Reset Interrupt
	ldr pc, reset_handler

	//Undefined Instruction
	ldr pc, basic_handler

	//Software Interrupt
	ldr pc, basic_handler

	//Prefetch Abort
	ldr pc, basic_handler

	//Data Abort
	ldr pc, basic_handler

	//Some random whole? What calls this?
	ldr pc, basic_handler

	//IRQ
	ldr pc, basic_handler

	//FIQ
	ldr pc, basic_handler

//Force compiler to store the branch command
//as a value into the respective register.
reset_handler:
	.word reset

basic_handler:
	.word arm_interrupt_handler

//Reset function. Automatically gets called due to program flow
reset:

	//Prepare to copy values over
	mov r0, #0x8000
	mov r1, #0x0000

	//Copy values
	ldmia r0!,{r2,r3,r4,r5,r6,r7,r8,r9}
	stmia r1!,{r2,r3,r4,r5,r6,r7,r8,r9}
	ldmia r0!,{r2,r3,r4,r5,r6,r7,r8,r9}
	stmia r1!,{r2,r3,r4,r5,r6,r7,r8,r9}

	//Call boot.S start function
	b _start
	bx lr

hang:
	b hang

//Interrupt Handler
arm_interrupt_handler:

	//Store return link
	sub r14, r14, #4
	stmfd sp!, {r0,r1,r2,r3,r4,r14}

	//Invoke C irq handler
	bl irq_handler

	//Restore values
	ldmfd sp!, {r0,r1,r2,r3,r4,pc}^
	bx lr
