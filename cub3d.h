/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-sous <tde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 15:55:56 by tde-sous          #+#    #+#             */
/*   Updated: 2023/10/20 09:53:04 by tde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <math.h>
# include <sys/wait.h>
# include "libft/libft.h"
# include <X11/X.h>
# include <X11/keysym.h>

# ifdef __APPLE__
#  include "mlx_macos/mlx.h"
# else
#  include "mlx_linux/mlx.h"
# endif

//	Video Resolution
# define S_WIDTH	1920.0
//	Video Resolution
# define S_HEIGHT	1080.0
// represents the height of one wall
# define WALL_HEIGHT 64.0
// represents half of one wall
# define HALF_WALL_HEIGHT 32.0
// Angle increment in degrees for rotation
# define ROTATION_ANGLE_INCREMENT	10.0
// // Amount of pixels to move in each step
# define PIXELS_PER_MOVE	5.0
# define W 119
# define A 97
# define S 115
# define D 100

typedef struct s_parsing
{
	char	*north_path;
	char	*south_path;
	char	*west_path;
	char	*east_path;
	int		ceiling_color;
	int		floor_color;
	char	**map;
	int		number_lines;
}	t_parsing;

typedef struct s_index
{
	int	texture_count;
	int	color_count;
	int	map_index;
}	t_index;

typedef struct s_minimap
{
	int	x;
	int	y;
	int	print_x;
	int	print_y;
	int	printed_x;
	int	printed_y;
}	t_minimap;

typedef struct s_texture_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_size;
	int		endian;

	int		bpp_north;
	int		l_len_north;
	int		endian_north;

	int		bpp_south;
	int		l_len_south;
	int		endian_south;

	int		bpp_west;
	int		l_len_west;
	int		endian_west;

	int		bpp_east;
	int		l_len_east;
	int		endian_east;

	int		bpp_ceiling;
	int		l_len_ceiling;
	int		endian_ceiling;

	char	*addr_north;
	char	*addr_south;
	char	*addr_west;
	char	*addr_east;
	char	*addr_ceiling;
}	t_texture_data;

typedef struct s_mlx
{
	t_texture_data	display_data;
	void			*mlx;
	void			*window;
	char			**map;
	int				width;
	int				height;

	char			*north_texture_path;
	char			*south_texture_path;
	char			*east_texture_path;
	char			*west_texture_path;

	char			*n_xpm;
	char			*s_xpm;
	char			*e_xpm;
	char			*w_xpm;
	void			*tile;
	void			*tree;
	void			*north_char;
	void			*south_char;
	void			*east_char;
	void			*west_char;

	double			player_view;

	double			x_player;
	double			y_player;

	double			x_step;
	double			y_step;

	int				x_m;
	int				y_m;

	char			player_direction;
	int				up;
	int				down;
	int				left;
	int				right;
	int				rot_l;
	int				rot_r;

	double			ray_distance;
	double			corrected_distance;

	int				ceiling_color;
	int				floor_color;

	double			ray_position;

	double			distance_to_projection;
	double			projection_3d;
	double			floor_ceiling_origin;
	char			*color;

	t_parsing		*parsing;
}	t_mlx;

// Check if the file ends with .cub.
void	check_file_extension(char **argv);
// Check if the program is passed a valid file argument.
int		validate_arguments(char **argv, int argc);
// Get the number of lines in a file given its file descriptor.
int		count_file_lines(int fd);
// Main parsing function to parse the input file.
void	parse_cub_file(int argc, char **argv, t_parsing *parsing);
// Check each line of the map for valid characters and player position.
void	validate_line_content(t_parsing *parsing, int index, int *player_index);
// Check if the map has a valid player position.
void	validate_map_and_player(t_parsing *parsing);
// Helper function to extract RGB color components.
int		update_color_components(char s, int *vergul, int *nbr, int *rgb);
// Check if the line contains valid color values.
int		validate_color(char *line);
// Extract the color value from a line.
int		get_color(char *line, char *str);
// Get color values from the parsing.
void	color_values(t_parsing *parsing, char *line, t_index *index);
// Error handling for parsing errors.
void	error_map(t_parsing *parsing);
// Error handling for invalid line format.
void	error_line(t_parsing *parsing);
// Error handling for invalid color values.
void	error_color(t_parsing *parsing);
// Initialize the parsing structure with default values.
void	initialize_parsing(t_parsing *parsing);
// Initialize the index structure with default values.
void	initialize_index(t_index *number);
// Assign the parsed line to the map.
void	process_map_line(t_parsing *parsing, t_index *index, char *line);
// Extract map info from the input file.
void	get_info_map(t_parsing *parsing, char *line, t_index \
	*index, int *n_tex);
// Read the map from the input file.
void	read_map(char *file, t_parsing *parsing);
// Check the surroundings of player characters.
void	is_invalid_player_position(t_parsing *parsing, int i, int index);
// Check the surroundings of '0' characters.
int		is_invalid_zero_position(t_parsing *parsing, int index, \
	char *line, int i);
// Get and check the texture path.
char	*get_path_check(char *line, char *ser);
// Assign texture paths to the parsing structure.
void	assign_texture_path(t_parsing *parsing, char *line, int *number \
	, t_index *index);
// Check if the line contains a valid texture specifier.
int		is_texture_line(char *line );
// Check if a character is a valid map character.
int		is_invalid_map_character(char c);
// Check if the line contains '0' characters.
int		contains_zero_character(char *str);
/* Loads XPM images for rendering and stores their data
	in the provided window structure.*/
void	images_to_xpm(t_mlx *window);
// Find the initial player position.
void	get_player_position(t_mlx *window);
// Calculate the distance between player and a wall.
double	distance_view(double y_player, double x_player, \
	double y_wall, double x_wall);
// Correct the distance based on fisheye effect.
double	correct_distance(t_mlx *mlx, double angle);
/* Sets the color of a pixel at the specified
coordinates in the image data structure. */
void	set_pixel_color(t_texture_data *data, int x, int y, int color);
// Set the player's direction based on the map coordinates.
char	set_directions(double y_coordinate, double x_coordinate, t_mlx *window);
/* Renders a 3D view of the scene based on the
provided distance and player direction. */
void	render_3d_view(double distance, int height, t_mlx *mlx, \
	char player_diretion);
/* Retrieves the color data for the north-facing wall
 texture based on the given index.*/
char	*north_texture(t_mlx *mlx, int i);
/* Retrieves the color data for the south-facing wall
 texture based on the given index.*/
char	*south_texture(t_mlx *mlx, int i);
/* Retrieves the color data for the east-facing wall
 texture based on the given index.*/
char	*east_texture(t_mlx *mlx, int i);
/* Retrieves the color data for the west-facing wall
 texture based on the given index.*/
char	*west_texture(t_mlx *mlx, int i);
// Performing the ray casting process to calculate rendering information.
void	calculate_ray_intersections(t_mlx *window, double angle, int x);
// Projects rays to render the 3D view of the scene.
void	projecting_game(t_mlx *window);
// Moves the player character backward.
void	move_backward(t_mlx *window);
// Moves the player character forward.
void	move_forward(t_mlx *window);
// Moves the player character left.
void	move_left(t_mlx *window);
// Moves the player character right.
void	move_right(t_mlx *window);
void	move_player(t_mlx *window);
void	rotate_left(t_mlx *window);
void	rotate_right(t_mlx *window);
// Handles keyboard input and triggers corresponding actions.
int		release_keys(int press, t_mlx *window);
// Handles keyboard input and triggers corresponding actions.
int		get_keys(int press, t_mlx *window);
// Print minimap to the screen
void	put_minimap(t_mlx *window);
int		game_loop(t_mlx *window);
void	hooks(t_mlx *window);
int		destroy_window(t_mlx *window);
int		is_wall_detector(t_mlx *window, int minus, double y_step \
	, double x_step);

/* Testing */

void	print_parsing_info(t_parsing *parsing);
void	print_index_info(t_index *index);
void	print_map(t_parsing *parsing);
#endif
