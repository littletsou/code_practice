This program is to remove folders which are not on the whitelist.

You need to specify the amount of folder "whitelist_num", and

names of each folder in the array "whitelist_name".

For example:

int whitelist_num = 4;
whitelist_name[0] = "wnc";
whitelist_name[1] = "test";
whitelist_name[2] = "asd";
whitelist_name[3] = "zxc";

Then this program will remove folders which are not in the array "whitelist_name".

Note: You must change the working directory to the target folder.