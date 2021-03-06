#include "Module_Loader/base.h"
#include "REPL_module/repl.h"
#include"Terminal_module/terminal.h"
#include"User_module/user.h"
#include<string.h>




char * base_su(const Args_struct *const args, Repl_data_struct * const repl_data){
	if (args->length>0){
		User_Info _use = { 0, (unsigned char *)args->args[0] };
		User_Info *const use = malloc(sizeof(User_Info));
		memmove(use, &_use, sizeof(User_Info));
		Terminal_data *ter = Apply_terminal(use);
		Apply_shell(ter);
	}
	else return "you should be enter login name.";
	return NULL;
}


char *base_module(const Args_struct *const args, Repl_data_struct * const repl_data){
	String_Array * string_array=Show_Module();
	if (string_array == NULL)return "NULL";
	char *cache = calloc(INIT_CACHE_SIZE, sizeof(char));
	for (int i = 0; i < string_array->len; i++){
		strcat(cache, string_array->String[i]);
		strcat(cache, "\n");
	}
	return cache;
}

char *base_time(const Args_struct *const args, Repl_data_struct * const repl_data){
	return Get_date("%Y/%m/%d %H:%M:%S");
}

char *base_help(const Args_struct *const args, Repl_data_struct * const repl_data){
	char *c = calloc(INIT_CACHE_SIZE, sizeof(char));
	strcpy(c, "this is Mylib help command\n");
	for (int i = 0; i < repl_data->cmd_list_stack->length; ++i){
		strcat(c, repl_data->cmd_list_stack->cmd_list[i]->cmd_name);
		if (i != repl_data->cmd_list_stack->length-1)strcat(c, "\n");

	}

	return c;
}

char *base_exit(const Args_struct *const args, Repl_data_struct * const repl_data)
{
	repl_data->state = 0;
	Kill_terminal(repl_data->terminal);
	return "exit success";
}

int Add_command_help_document(){
	return EXIT_SUCCESS;
}
int Init_base_command(CMD_list_stack *cmd_list_stack)
{
	Add_command(cmd_list_stack, "su", base_su);
	Add_command(cmd_list_stack, "show_module", base_module);
	Add_command(cmd_list_stack, "time", base_time);
	Add_command(cmd_list_stack, "help", base_help);
	Add_command(cmd_list_stack, "exit", base_exit);
	return EXIT_SUCCESS;
}

