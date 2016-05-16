void go_right(snake cobra){
  int size=cobra.size;
  int i;
  ring *body=cobra.body;
  // check if the command is possible
  int check_command=(body[0].x+1!=body[1].x || body[0].y!=body[1].y);
  // set body
  // each ring get the previous ring position
  if(!check_command)return;
  for(i=size-1;i>0;i--){
    body[i].x=body[i-1].x;
    body[i].y=body[i-1].y;
  }
  // set the head
  body[0].x++;
  if(is_barrer(body[0].x,body[0].y))
    body[0].x=1;
}

void go_left(snake cobra){
  int size=cobra.size;
  int i;
  ring *body=cobra.body;
  // check if the command is possible
  int check_command=(body[0].x-1!=body[1].x || body[0].y!=body[1].y);
  if(!check_command)
    return;
  // set body, each ring get the previous ring position
  for(i=size-1;i>0;i--){
    body[i].x=body[i-1].x;
    body[i].y=body[i-1].y;
  }

  // set the head
  body[0].x--;
  if(is_barrer(body[0].x,body[0].y))
    body[0].x=cols-1;
}

void go_up(snake cobra){
  int size=cobra.size;
  int i;
  ring *body=cobra.body;
  // check if the command is possible
  int check_command=(body[0].y-1!=body[1].y || body[0].x!=body[1].x);
  if(!check_command)return;
  // set body, each ring get the previous ring position
  for(i=size-1;i>0;i--){
    body[i].x=body[i-1].x;
    body[i].y=body[i-1].y;
  }

  // set the head
  body[0].y--;
  if(is_barrer(body[0].x,body[0].y))
    body[0].y=rows-2;
}

void go_bottom(snake cobra){
  int size=cobra.size;
  int i;
  ring *body=cobra.body;
  // check if the command is possible
  int check_command=(body[0].y+1!=body[1].y || body[0].x!=body[1].x);
  if(!check_command)return;
  // set body, each ring get the previous ring position
  for(i=size-1;i>0;i--){
    body[i].x=body[i-1].x;
    body[i].y=body[i-1].y;
  }

  // set the head
  body[0].y++;
  if(is_barrer(body[0].x,body[0].y))
    body[0].y=1;
}
