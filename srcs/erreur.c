/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erreur.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduchemi <aduchemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 17:29:28 by aduchemi          #+#    #+#             */
/*   Updated: 2020/05/06 17:58:33 by aduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_err_handl(int error)
{
	ft_putstr("Error\n");
	if (error == -2)
		ft_putstr("Erreur lors de la création du fichier bitmap\n");
	else if (error == -3)
		ft_putstr("Erreur parsing : résolution incorrecte\n");
	else if (error == -4)
		ft_putstr("Erreur parsing : couleur sol incorrecte\n");
	else if (error == -5)
		ft_putstr("Erreur parsing : couleur plafond incorrecte\n");
	else if (error == -6)
		ft_putstr("Erreur parsing : texture nord manquante\n");
	else if (error == -7)
		ft_putstr("Erreur parsing : texture sud manquante\n");
	else if (error == -8)
		ft_putstr("Erreur parsing : texture est manquante\n");
	else if (error == -9)
		ft_putstr("Erreur parsing : texture ouest manquante\n");
	else if (error == -10)
		ft_putstr("Erreur parsing : texture sprite manquante\n");
	else if (error == -11)
		ft_putstr("Erreur lors du traitement du fichier .cub (GNL)\n");
	else
		return (ft_err_handl_suite(error));
	return (error);
}

int	ft_err_handl_suite(int error)
{
	if (error == -12)
		ft_putstr("Erreur parsing : chemin texture nord corrompu\n");
	else if (error == -13)
		ft_putstr("Erreur parsing : chemin texture sud corrompu\n");
	else if (error == -14)
		ft_putstr("Erreur parsing : chemin texture est corrompu\n");
	else if (error == -15)
		ft_putstr("Erreur parsing : chemin texture ouest corrompu\n");
	else if (error == -16)
		ft_putstr("Erreur parsing : chemin texture sprite corrompu\n");
	else if (error == -17)
		ft_putstr("Erreur lors de l'ouverture du fichier .cub\n");
	else if (error == -18)
		ft_putstr("Erreur lors de l'allocation mémoire de la map\n");
	else if (error == -19)
		ft_putstr("Erreur parsing : pas de position renseignée\n");
	else if (error == -20)
		ft_putstr("Erreur parsing : plusieurs positions renseignées\n");
	else if (error == -21)
		ft_putstr("Erreur parsing : map non entourée de murs\n");
	else
		return (ft_err_handl_suite_bis(error));
	return (error);
}

int	ft_err_handl_suite_bis(int error)
{
	if (error == -22)
		ft_putstr("Erreur parsing : personnage hors de la map/\
dans map ouverte\n");
	else if (error == -23)
		ft_putstr("Nombre d'arguments incorrect\n");
	else if (error == -24)
		ft_putstr("Erreur parsing : map incorrecte\n");
	else if (error == -25)
		ft_putstr("Erreur parsing : ligne incorrecte\n");
	else if (error == -26)
		ft_putstr("Erreur parsing : texture renseignée plusieurs fois\n");
	else if (error == -27)
		ft_putstr("Erreur parsing : sprite non entouré de murs\n");
	else if (error == -28)
		ft_putstr("Le fichier paramètre doit être au format .cub\n");
	return (error);
}

int	ft_doop_err_path(char *line)
{
	if (line[0] == 'N' && line[1] == 'O')
		return (ft_err_handl(-12));
	else if (line[0] == 'S' && line[1] == 'O')
		return (ft_err_handl(-13));
	else if (line[0] == 'E' && line[1] == 'A')
		return (ft_err_handl(-14));
	else if (line[0] == 'W' && line[1] == 'E')
		return (ft_err_handl(-15));
	else if (line[0] == 'S' && line[1] != 'O')
		return (ft_err_handl(-16));
	return (0);
}

int	ft_err_perso(int perso)
{
	if (perso == 0)
		return (ft_err_handl(-19));
	else if (perso > 1)
		return (ft_err_handl(-20));
	return (0);
}
