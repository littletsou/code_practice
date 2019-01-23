#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <stdbool.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>
bool is_dir(const char *path)
{
    struct stat statbuf;
    if (lstat(path, &statbuf) == 0)
    {
        return S_ISDIR(statbuf.st_mode) != 0;
    }
    return false;
}

bool is_file(const char *path)
{
    struct stat statbuf;
    if (lstat(path, &statbuf) == 0)
        return S_ISREG(statbuf.st_mode) != 0;
    return false;
}

bool is_special_dir(const char *path)
{
    return strcmp(path, ".") == 0 || strcmp(path, "..") == 0;
}

void get_file_path(const char *path, const char *file_name, char *file_path)
{
    strcpy(file_path, path);
    if (file_path[strlen(path) - 1] != '/')
        strcat(file_path, "/");
    strcat(file_path, file_name);
}

void delete_file(const char *path)
{
    DIR *dir;
    struct dirent *dir_info;
    char file_path[PATH_MAX];
    if (is_file(path))
    {
        remove(path);
        return;
    }
    if (is_dir(path))
    {
        if ((dir = opendir(path)) == NULL)
        {
            return;
        }
        while ((dir_info = readdir(dir)) != NULL)
        {
            get_file_path(path, dir_info->d_name, file_path);
            if (is_special_dir(dir_info->d_name))
                continue;
            //printf("%s\n", file_path);
            delete_file(file_path);
            rmdir(file_path);
        }
    }
}

int main()
{
    //Read directory name
    DIR *dp;
    struct dirent *ep;
    dp = opendir("./");
    int max_dir_num = 1000;
    char *dir_name[max_dir_num];
    int dir_num = 0;
    if (dp != NULL)
    {
        while (ep = readdir(dp))
        {
            if (ep->d_type == DT_DIR)
            {
                if (strcmp(ep->d_name, ".") != 0 && strcmp(ep->d_name, "..") != 0)
                {
                    dir_name[dir_num] = ep->d_name;
                    dir_num++;
                }
            }
        }
        (void)closedir(dp);
    }
    else
    {
        printf("Couldn't open the directory\n");
        return 1;
    }
    printf("dir_name\n");
    for (int i = 0; i < dir_num; i++)
    {
        printf("%s\n", dir_name[i]);
    }
    printf("dir_num %d\n", dir_num);
    bool test;
    test = false;
    if (test)
    {
        return 0;
    }
    printf("===========================\n\n");

    //Define whitelist
    int whitelist_num = 4;
    char *whitelist_name[whitelist_num];
    whitelist_name[0] = "wnc";
    whitelist_name[1] = "test";
    whitelist_name[2] = "asd";
    whitelist_name[3] = "zxc";
    //whitelist_name[4] = "qwe";

    printf("whitelist_name\n");
    for (int i = 0; i < whitelist_num; i++)
    {
        printf("%s\n", whitelist_name[i]);
    }
    printf("whitelist_num %d\n", whitelist_num);

    test = false;
    if (test)
    {
        return 0;
    }
    printf("===========================\n\n");

    //List those folders which are not on the whitelist
    int delete_num = 0;
    char *delete_name[max_dir_num];
    bool del = true;
    for (int i = 0; i < dir_num; i++)
    {
        del = true;
        for (int j = 0; j < whitelist_num; j++)
        {
            //printf("%s  %s\n", dir_name[i], whitelist_name[j]);
            if (!(strcmp(dir_name[i], whitelist_name[j])))
            {
                //printf("%s  %s\n", dir_name[i], whitelist_name[j]);
                del = false;
                break;
            }
        }
        if (del)
        {
            delete_name[delete_num++] = dir_name[i];
        }
    }
    printf("===========================\n\n");
    printf("delete_name\n");
    for (int i = 0; i < delete_num; i++)
    {
        printf("%s\n", delete_name[i]);
    }
    printf("delete_num %d\n", delete_num);

    test = false;
    if (test)
    {
        return 0;
    }
    //Delete those folders
    char temp[80];
    for (int i = 0; i < delete_num; i++)
    {
        strcpy(temp, "./");
        strcat(temp, delete_name[i]);
        delete_file(temp);
        rmdir(temp);
        //printf("%s\n", temp);
    }
    printf("===========================\n\n");

    return 0;
}
