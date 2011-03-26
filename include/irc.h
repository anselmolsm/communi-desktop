/*
* Copyright (C) 2008-2011 J-P Nurmi <jpnurmi@gmail.com>
*
* This library is free software; you can redistribute it and/or modify it
* under the terms of the GNU Lesser General Public License as published by
* the Free Software Foundation; either version 2 of the License, or (at your
* option) any later version.
*
* This library is distributed in the hope that it will be useful, but WITHOUT
* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
* FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public
* License for more details.
*/

#ifndef IRC_H
#define IRC_H

#include <ircglobal.h>
#include <QtCore/qobject.h>

class IRC_EXPORT Irc
{
    Q_GADGET
    Q_ENUMS(Code)

public:
    enum Code
    {
        RPL_WELCOME                = 001,
        RPL_YOURHOST               = 002,
        RPL_CREATED                = 003,
        RPL_MYINFO                 = 004,
        RPL_BOUNCE                 = 005,

        RPL_USERHOST               = 302,
        RPL_ISON                   = 303,
        RPL_AWAY                   = 301,
        RPL_UNAWAY                 = 305,
        RPL_NOWAWAY                = 306,

        RPL_WHOISUSER              = 311,
        RPL_WHOISSERVER            = 312,
        RPL_WHOISOPERATOR          = 313,
        RPL_WHOISIDLE              = 317,
        RPL_ENDOFWHOIS             = 318,
        RPL_WHOISCHANNELS          = 319,
        RPL_WHOWASUSER             = 314,
        RPL_ENDOFWHOWAS            = 369,

        RPL_LIST                   = 322,
        RPL_LISTEND                = 323,

        RPL_UNIQOPIS               = 325,
        RPL_CHANNELMODEIS          = 324,
        RPL_CHANNELURL             = 328,
        RPL_CHANNELCREATED         = 329,

        RPL_NOTOPIC                = 331,
        RPL_TOPIC                  = 332,
        RPL_TOPICSET               = 333,

        RPL_INVITING               = 341,
        RPL_SUMMONING              = 342,

        RPL_INVITELIST             = 346,
        RPL_ENDOFINVITELIST        = 347,

        RPL_EXCEPTLIST             = 348,
        RPL_ENDOFEXCEPTLIST        = 349,

        RPL_VERSION                = 351,

        RPL_WHOREPLY               = 352,
        RPL_ENDOFWHO               = 315,

        RPL_NAMREPLY               = 353,
        RPL_ENDOFNAMES             = 366,

        RPL_LINKS                  = 364,
        RPL_ENDOFLINKS             = 365,

        RPL_BANLIST                = 367,
        RPL_ENDOFBANLIST           = 368,

        RPL_INFO                   = 371,
        RPL_ENDOFINFO              = 374,

        RPL_MOTDSTART              = 375,
        RPL_MOTD                   = 372,
        RPL_ENDOFMOTD              = 376,

        RPL_YOUREOPER              = 381,
        RPL_REHASHING              = 382,
        RPL_YOURESERVICE           = 383,

        RPL_TIME                   = 391,
        RPL_USERSSTART             = 392,

        RPL_USERS                  = 393,
        RPL_ENDOFUSERS             = 394,
        RPL_NOUSERS                = 395,

        RPL_TRACELINK              = 200,
        RPL_TRACECONNECTING        = 201,
        RPL_TRACEHANDSHAKE         = 202,
        RPL_TRACEUNKNOWN           = 203,
        RPL_TRACEOPERATOR          = 204,
        RPL_TRACEUSER              = 205,
        RPL_TRACESERVER            = 206,
        RPL_TRACESERVICE           = 207,
        RPL_TRACENEWTYPE           = 208,
        RPL_TRACECLASS             = 209,
        RPL_TRACELOG               = 261,
        RPL_TRACEEND               = 262,

        RPL_STATSLINKINFO          = 211,
        RPL_STATSCOMMANDS          = 212,
        RPL_ENDOFSTATS             = 219,
        RPL_STATSUPTIME            = 242,
        RPL_STATSOLINE             = 243,

        RPL_UMODEIS                = 221,

        RPL_SERVLIST               = 234,
        RPL_SERVLISTEND            = 235,

        RPL_LUSERCLIENT            = 251,
        RPL_LUSEROP                = 252,
        RPL_LUSERUNKNOWN           = 253,
        RPL_LUSERCHANNELS          = 254,
        RPL_LUSERME                = 255,

        RPL_ADMINME                = 256,
        RPL_ADMINLOC1              = 257,
        RPL_ADMINLOC2              = 258,
        RPL_ADMINEMAIL             = 259,

        RPL_TRYAGAIN               = 263,

        ERR_NOSUCHNICK             = 401,
        ERR_NOSUCHSERVER           = 402,
        ERR_NOSUCHCHANNEL          = 403,
        ERR_CANNOTSENDTOCHAN       = 404,
        ERR_TOOMANYCHANNELS        = 405,
        ERR_WASNOSUCHNICK          = 406,
        ERR_TOOMANYTARGETS         = 407,
        ERR_NOSUCHSERVICE          = 408,
        ERR_NOORIGIN               = 409,
        ERR_NORECIPIENT            = 411,
        ERR_NOTEXTTOSEND           = 412,
        ERR_NOTOPLEVEL             = 413,
        ERR_WILDTOPLEVEL           = 414,
        ERR_BADMASK                = 415,
        ERR_UNKNOWNCOMMAND         = 421,
        ERR_NOMOTD                 = 422,
        ERR_NOADMININFO            = 423,
        ERR_FILEERROR              = 424,
        ERR_NONICKNAMEGIVEN        = 431,
        ERR_ERRONEUSNICKNAME       = 432,
        ERR_NICKNAMEINUSE          = 433,
        ERR_NICKCOLLISION          = 436,
        ERR_UNAVAILRESOURCE        = 437,
        ERR_USERNOTINCHANNEL       = 441,
        ERR_NOTONCHANNEL           = 442,
        ERR_USERONCHANNEL          = 443,
        ERR_NOLOGIN                = 444,
        ERR_SUMMONDISABLED         = 445,
        ERR_USERSDISABLED          = 446,
        ERR_NOTREGISTERED          = 451,
        ERR_NEEDMOREPARAMS         = 461,
        ERR_ALREADYREGISTRED       = 462,
        ERR_NOPERMFORHOST          = 463,
        ERR_PASSWDMISMATCH         = 464,
        ERR_YOUREBANNEDCREEP       = 465,
        ERR_YOUWILLBEBANNED        = 466,
        ERR_KEYSET                 = 467,
        ERR_CHANNELISFULL          = 471,
        ERR_UNKNOWNMODE            = 472,
        ERR_INVITEONLYCHAN         = 473,
        ERR_BANNEDFROMCHAN         = 474,
        ERR_BADCHANNELKEY          = 475,
        ERR_BADCHANMASK            = 476,
        ERR_NOCHANMODES            = 477,
        ERR_BANLISTFULL            = 478,
        ERR_NOPRIVILEGES           = 481,
        ERR_CHANOPRIVSNEEDED       = 482,
        ERR_CANTKILLSERVER         = 483,
        ERR_RESTRICTED             = 484,
        ERR_UNIQOPPRIVSNEEDED      = 485,
        ERR_NOOPERHOST             = 491,
        ERR_UMODEUNKNOWNFLAG       = 501,
        ERR_USERSDONTMATCH         = 502
    };

    static const char* version();
    static const char* toString(Code code);
};

#endif // IRC_H
