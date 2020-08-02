/*
 * Copyright (C) 2017 XRADIO TECHNOLOGY CO., LTD. All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *    1. Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *    2. Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the
 *       distribution.
 *    3. Neither the name of XRADIO TECHNOLOGY CO., LTD. nor the names of
 *       its contributors may be used to endorse or promote products derived
 *       from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 *  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 *  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "common/cmd/cmd_util.h"
#include "common/cmd/cmd.h"
#include "fat01.h"

#if PRJCONF_NET_EN

#define COMMAND_IPERF 1
#define COMMAND_PING 1

static enum cmd_status exec_test(char *cmd)
{

	CMD_LOG(1, "$输入的命令是 = %s，欢迎您", cmd);
	return CMD_STATUS_OK;
};

static enum cmd_status list_files(char *cmd)
{

	fs_scan_files(cmd);

	return CMD_STATUS_OK;
};

static const struct cmd_data custom_cmds[] = {
    {"test", exec_test},
    {"list", list_files}};

static enum cmd_status execute_custom_cmd(char *cmd)
{
	return cmd_exec(cmd, custom_cmds, nitems(custom_cmds));
};

static const struct cmd_data main_cmds[] = {
    {"hello", execute_custom_cmd}};

void main_cmd_exec(char *cmd)
{
	enum cmd_status status;
	if (cmd[0] != '\0')
	{
		CMD_LOG(1, "$您输入的命令是 = %s\n", cmd);

		status = cmd_exec(cmd, main_cmds, nitems(main_cmds));

		if (status != CMD_STATUS_ACKED)
		{
			cmd_write_respond(status, cmd_get_status_desc(status));
		}
	}
	else
	{
		/*命令为空*/
		CMD_LOG(1, "$\n");
		CMD_LOG(0, "结束");
	}
}
#endif
