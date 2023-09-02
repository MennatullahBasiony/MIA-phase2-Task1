/*
* file: 01200838721_Task1_3.c
* Author: Menna Elmahdy
* Description: Task Manager
*/

#include <stdio.h>
#include <stdlib.h>

void addTasks(char *list[], int *iter);
void removeTask(char *list[], int *iter, int *tasksDone[]);
void completeTasks(int *tasksDone[], int iter);
void viewTasks(char *list[], int iter, int tasksDone[]);


int main()
{
    //Declaring array of pointers of type char that would point to tasks string entered by user
    char *list[200];
    //Variables that would be needed in managing tasks
    int selection = 0, iter = 0, tasksDone[200];

    for(int i = 0; i < 200; i++)
    {
        //Assigning enough space for each task
        list[i] = (char*)malloc(100*sizeof(char));
        tasksDone[i] = 0;
    }

    do
    {
        //Always printing the menu for user
        printf("\nMinions Task Manager\n1.Add Task\n2.View Tasks\n3.Remove Task\n4.Mark Task as Completed\n5.Exit\n\nSelect an option: ");
        scanf("%d", &selection);

        switch(selection)
        {
        case 1:
            addTasks(list, &iter);
            break;

        case 2:
            viewTasks(list, iter, tasksDone);
            break;

        case 3:
            removeTask(list, &iter, &tasksDone);
            break;

        case 4:
            completeTasks(&tasksDone, iter);
            break;

        case 5:
            printf("\n\nExiting Minions Task Manager. Have a great day!\n");
            break;

        default:
            printf("\n\nSelection out of boundaries\n");
        }
    }
    while(selection != 5);


    return 0;
}


void addTasks(char *list[], int *iter)
{
    printf("\n\nEnter task description: ");
    //It will only take enough 99 characters string that would fit in our list
    scanf("%99s", list[*iter]);
    //Incrementing iter that holds number of tasks
    ++ (*iter);
    printf("\nTask added\n");
}

void removeTask(char *list[], int *iter, int *tasksDone[])
{
    int id;
    printf("\n\nEnter task ID to remove: ");
    scanf("%d", &id);

    //checking valid ID number
    if((*iter) <= id-1 || id < 1)    printf("\nInvalid ID!\n");
    else
    {
        for(int i = id-1; i <= (*iter)-1; i ++)
        {
            if((*iter) == 1)    // if there is only one task just update tasksDone array to 0
            {
                tasksDone[i] = 0;
                continue;
            }

            list[i] = list[i + 1];  //Move all tasks after the one to be removed one step to the back
            tasksDone[i] = tasksDone[i + 1];    //Update tasksDone array in same way
        }
        -- (*iter); //decrement iter by one
        printf("\nTask Removed\n");
    }

}

void completeTasks(int *tasksDone[], int iter)
{
    int id;
    printf("\nEnter Task id you want to mark as completed: ");
    scanf("%d", &id);

    //checking for valid id input
    if(id-1 >=iter || id < 1)   printf("\nInvalid ID\n");

    //if task not Done mark as Done
    else if(tasksDone[id - 1] != 1)
    {
        tasksDone[id - 1] = 1;
        printf("\nTask marked as Completed \n");
    }
    else if(tasksDone[id - 1] == 1) printf("\nTask already Completed\n");   //if task already done just inform user
}

void viewTasks(char *list[], int iter, int tasksDone[])
{
    if(iter == 0)   printf("\nNo Tasks To Show\n");
    else
    {
        printf("\nCurrent Tasks: \n");
        int p = 0;
        while(p < iter)
        {
            //show the id, description and completeness state of each task
            printf("\nTask ID: %d\nDescription: %s\nCompleted: %s\n", (p + 1), list[p], (tasksDone[p] == 1? "Done": "Not Yet"));
            ++ p;
        }
    }

}

