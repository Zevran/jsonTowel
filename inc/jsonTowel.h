/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jsonTowel.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaelreyrol <gaelreyrol@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/07 02:56:31 by gaelreyrol        #+#    #+#             */
/*   Updated: 2014/02/07 04:14:44 by gaelreyrol       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef JSON_TOWEL_H
#define JSON_TOWEL_H

/*
** JSON Type Identifier :
** - Object		: "data":
** - Array		: {"data", "data"}
** - String		: "data"
** - Boolean	: true, false
** - NULL		: Null
*/
typedef enum	e_jsonType
{
	JS_OBJECT	= 0,
	JS_ARRAY	= 1,
	JS_STRING	= 2,
	JS_NUMBER	= 3,
	JS_BOOL		= 4,
	JS_NULL		= 5
}				t_jsonType;

/*
** JSON Error Event :
** - NOMEMORY	: Memory allocation has failed
** - INVALID	: Invalid character
** - SYNTAX		: Syntax error in string
** - DATA 		: Missing part of JSON packet
*/
typedef enum	e_jsonError
{
	JS_ERROR_NOMEMORY	= -1,
	JS_ERROR_INVALID	= -2,
	JS_ERROR_SYNTAX		= -3,
	JS_ERROR_DATA		= -4,
	JS_SUCCESS			= 0
}				t_jsonError;

/*
** JSON Token structure :
** @param  type [jsonType Enum]
** @param  start [Starting index token]
** @param  end [Ending index token]
** @param  len [Token total size]
** @param  parent [Index parent token]
*/
typedef struct	s_jsonToken
{
	t_jsonType	type;
	int			start;
	int			end;
	int			len;
	int			parent;
}				t_jsonToken;

/*
** JSON Parser structure :
** @param  pos [offset (position) in the string]
** @param  next_token [next token to allocate]
** @param  parent_token [parent token node]
*/
typedef struct	s_jsonParser
{
	t_uint	pos;
	int		next_token;
	int		parent_token;
}				t_jsonParser;

/*
** [jsonTowel_parse Parse the given string in JSON format]
** @param  parser [Struct pointer (t_jsonParser)]
** @param  string [Formated string with JSON syntax]
** @param  tokens [Struct pointer (t_jsonToken)]
** @param  nb_tok [Number of tokens found]
** @return        [Status of parsed string (t_jsonError)]
*/
t_jsonError	jsonTowel_parse(t_jsonParser *parser, const char *string,
							t_jsonToken *tokens, t_uint nb_tok);

/**
** [jsonTowel_file Parse the given file in JSON format]
** @param  parser [Struct pointer (t_jsonParser)]
** @param  string [Formated string with JSON syntax]
** @param  tokens [Struct pointer (t_jsonToken)]
** @param  nb_tok [Number of tokens found]
** @return        [Status of parsed string (t_jsonError)]
*/
t_jsonError	jsonTowel_file(t_jsonParser *parser, const char *string,
						   t_jsonToken *tokens, t_uint nb_tok);

#endif /* !JSON_TOWEL_H */
