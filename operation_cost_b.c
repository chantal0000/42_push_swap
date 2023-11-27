// cost analyse function, calculates the cost of each push, the sum of
// the amount of operations it would take to put the target node and b on top
void	operation_cost(t_stack *a, t_stack *b)
{
	//write(1, "operation_cost\n", 15);
	// int for length of a and b
	int	a_len;
	int	b_len;
	// fill len
	a_len = stack_len(a);
	b_len = stack_len(b);

	// loop through b
	while (b)
	{
		// b price is = b index
		b->operations_cost = b->i;
		// if b above median is false
		if (!(b->above_median))
		{
			// b price is = leb_b - index of b
			b->operations_cost = b_len - b->i;
			write(1, "operation_cost\n", 15);
		}
		// if b target node is above median
		if (b->target_node->above_median)
		{// b price = b price + b->target_node->currennt_position
			write(1, "operation_cost\n", 15);
			b->operations_cost = b->operations_cost + b->target_node->i;
		}
		// else meaning b is above median and its target node in a is below median
		else
		{
			// price b = price b + len_a - (b->target?node->current_position)
			write(1, "operation_cost\n", 15);
			b->operations_cost = b->operations_cost - (b->target_node->i);
		}
		b = b->next;
	}
}
