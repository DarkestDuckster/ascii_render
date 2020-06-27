#include <stdlib.h>

#include "selectable.h"

int
get_selected(Selectable selectable)
{
    Selectable base = GET_SELECTABLE(selectable);
    return base->variables.selected;
}

void
select_renderable(Selectable selectable)
{
    Selectable base = GET_SELECTABLE(selectable);
    base->variables.selected = 1;
    
    if (base->function_base->select_function != 0)
        base->function_base->select_function(selectable);
}

void
delete_selectable(Selectable selectable)
{
    Selectable base = GET_SELECTABLE(selectable);
    free(base);
}
