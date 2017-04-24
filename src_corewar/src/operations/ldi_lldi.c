
#include <corewar.h>

static t_op_arg	calc_ldi_offset(struct s_process *process,
				struct s_parameter *params)
{
	union u_val	first;
	union u_val	second;

	if (params[0].param_type == T_REG)
		reverse_bytes((void *)&process->registors[params[0].param_val.val], 
			REG_SIZE, first.arr);
	else
		reverse_bytes(params[0].param_val.arr, IND_SIZE, first.arr);
	if (params[1].param_type == T_REG)
		reverse_bytes((void *)&process->registors[params[1].param_val.val], 
		REG_SIZE, second.arr);
	else
		reverse_bytes(params[1].param_val.arr, IND_SIZE, second.arr);
	return ((first.val + second.val) % IDX_MOD);
}

/*
**	> Make sure to validate that parse params is shortening directs
**		to indirect size when op.c indicates to do so.
**	> Should I add the second param, then modulo, or do as the instructions say
**		and add the second param after the mod?
**	> Is the carry only modified if the function runs?
*/
int		ldi(struct s_game *game, struct s_process *process)
{
	struct s_parameter	params[g_op_tab[9].argc];
	uint8_t				*pc_temp;
	t_op_arg		offset;

	pc_temp = process->pc;
	if (-1 == parse_and_validate_parameters(game, process, &pc_temp, params))
		return (-1);
	process->pc = pc_temp;
	modify_carry(process);
	if (-1 == check_registors(process->op_code, params))
		return (0);
	offset = calc_ldi_offset(process, params);
	read_arena(game->arena, process->pc + (offset % IDX_MOD),
		(void *)&process->registors[params[2].param_val.val], REG_SIZE);
	return (0);
}

int		lldi(struct s_game *game, struct s_process *process)
{
	struct s_parameter	params[g_op_tab[9].argc];
	uint8_t				*pc_temp;
	t_op_arg		offset;

	pc_temp = process->pc;
	if (-1 == parse_and_validate_parameters(game, process, &pc_temp, params))
		return (-1);
	process->pc = pc_temp;
	modify_carry(process);
	if (-1 == check_registors(process->op_code, params))
		return (0);
	offset = calc_ldi_offset(process, params);
	read_arena(game->arena, process->pc + (offset % IDX_MOD),
		(void *)&process->registors[params[2].param_val.val], REG_SIZE);
	return (0);
}