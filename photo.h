//
//  photo.h
//  Hash_code
//
//  Created by Dayrabekov Artem on 2/28/19.
//  Copyright © 2019 Dayrabekov Artem. All rights reserved.
//

#ifndef photo_h
#define photo_h

typedef struct	s_photo
{
	int		tags_len;
	char	**tags;
	int		first_num;
	int		second_num;//-1 if it will be horizobtal
}				t_photo;

#endif /* photo_h */
