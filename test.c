#include <othm_object.h>
#include <othm_tag.h>
#include <othm_thread.h>
#include <othm_base.h>

struct othm_stack *stack_gen(void)
{
	struct othm_stack *stack;
	stack = malloc(sizeof(struct othm_stack));

	return stack;
}

struct othm_list *ogst_list_gen(void)
{
	struct othm_obj_tag *tagged =
		malloc(sizeof(struct othm_obj_tag) +
		       sizeof(struct othm_list));
	tagged->mutability = 0;
	/* tagged->data_form = ogst_list_form; */
	return OTHM_GET_TAGGED_LEFT(struct othm_list *,
				    tagged);
}

OTHM_CHAIN_DEFUN(dot, dot)
{
	struct othm_stack *stack;
	struct othm_symbol_struct *symbol;

	stack = control->state;
	symbol = othm_stack_pop(stack);

	othm_symbol_print(symbol);
	printf("\n");
}

OTHM_SYMBOL_INIT(popped);

int main(void)
{
	struct othm_stack *stack;

        stack = othm_stack_new(stack_gen);
	othm_stack_push(stack, OTHM_SYMBOL(popped));

	struct othm_list *chain =
		OTHM_CHAIN_DIRECT(ogst_list_gen, dot);

    /* printf("Waiting for a connection...\n"); */
	/* int i = 0; */
	/* while (1) { */

	struct othm_thread *thread = othm_thread_new(9, chain, NULL,
						     NULL, stack);
	othm_thread_start(thread);

	pthread_exit(NULL);
	return 0;
}
