# CUB3D

while (list->next)
{
    if (is_empty_line(list->content))
    {
        if (!ft_chk_map(list->content)
            && (ft_chk_txt(list->next->content)
                && ft_chk_color(list->next->content)))
            list->ismap = true;
    }
    list = list->next;
}
while (current->next && !current->ismap)
{
    if (is_empty_line(current->content))
    {
        if ((ft_chk_txt(current->content) && ft_chk_color(current->content))
            || (ft_chk_dup(&current, current->content, 3)
                && ft_chk_dup(&current, current->content, 2)))
                current->valid = false;
    }
    current = current->next;
}

// while (list->next)
// {
// 	if (is_empty_line(list->content))
// 	{
// 		if (!ft_chk_map(list->content)
// 			&& (ft_chk_txt(list->next->content)
// 				&& ft_chk_color(list->next->content)))
// 			list->ismap = true;
// 	}
// 	list = list->next;
// }