#include <stdlib.h>

#include "renderable.h"

void
create_render_base(Renderable new_renderable,
                   RenderFunction_t render_function,
                   DeleteFunction_t delete_function)
{
    new_renderable->render_function = render_function;
    new_renderable->delete_function = delete_function;
}

void *
get_object(Renderable renderable)
{
    return renderable;
}

RenderFunction_t
get_render_function(Renderable renderable)
{
    return renderable->render_function;
}

DeleteFunction_t
get_delete_function(Renderable renderable)
{
    return renderable->delete_function;
}

void
render_unto_screen(Renderable object_to_render, Screen screen_to_render_on)
{
    Renderable base = GET_RENDERABLE(object_to_render);
    get_render_function(base)(get_object(object_to_render), screen_to_render_on);
}

void
delete_renderable(Renderable renderable)
{
    Renderable base = GET_RENDERABLE(renderable);
    DeleteFunction_t delete_function = get_delete_function(base);
    void *object = get_object(renderable);
    
    delete_function(object);
}
