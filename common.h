#ifndef COMMON_H
#define COMMON_H

/* local das anotações!!

  Padrões de mensagens:

  from client to server

  // User related commands
  U_NEW <user_name> <client_version>
  U_RENAME <user_id> <new_user_name>

  // Message related commands
  M_TEXT <timestamp> <user_id> <msg>
  M_WHISP <timestamp> <user_id> <user_id> <msg>

  // Game related commands
  C_MOVE <user_id>
  C_DICE <user_id> [<min>] <max>

  from server to client

  NEWUSER <user_id> <user_name>
  REMOVEUSER <user_id>
*/

enum MESSAGE_CODES{

  USER_FIRST=100,
  USER_NEW=101,
  USER_RENAME=102,
  USER_LAST=199,

  MESSAGE_FIRST=200,
  MESSAGE_TEXT=201,
  MESSAGE_WHISPER=202,
  MESSAGE_LAST=299,

  COMMAND_FIRST=300,
  COMMAND_MOVE=301,
  COMMAND_DICE=302,
  COMMAND_LAST=399,

};

#endif // COMMON_H
