CREATE TABLE `jhpark_userinfo` (
  `seq` int(11) NOT NULL AUTO_INCREMENT,
  `user_uid` varchar(255) CHARACTER SET utf8 DEFAULT NULL,
  `user_id` varchar(255) CHARACTER SET utf8 DEFAULT NULL,
  `user_name` varchar(255) CHARACTER SET utf8 DEFAULT NULL,
  `user_gender` varchar(255) CHARACTER SET utf8 DEFAULT NULL,
  `link` varchar(255) CHARACTER SET utf8 DEFAULT NULL,
  `user_photo_url` varchar(255) CHARACTER SET utf8 DEFAULT NULL,
  `device` varchar(255) CHARACTER SET utf8 DEFAULT NULL,
  `ip` varchar(255) CHARACTER SET utf8 DEFAULT NULL,
  `regdate` varchar(255) CHARACTER SET utf8 DEFAULT NULL,
  PRIMARY KEY (`seq`)
) ENGINE=MyISAM AUTO_INCREMENT=1 DEFAULT CHARSET=utf8;
