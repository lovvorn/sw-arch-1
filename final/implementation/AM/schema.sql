-- --------------------------------------------------------

--
-- Table structure for table `Customer`
--

CREATE TABLE IF NOT EXISTS `Customer` (
  `id` int(11) NOT NULL,
  `name` varchar(100) DEFAULT NULL,
  `address` varchar(100) DEFAULT NULL,
  `balance` decimal(10,2) DEFAULT NULL,
  `profit` decimal(10,2) DEFAULT NULL,
  `loss` decimal(10,2) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `Portfolio`
--

CREATE TABLE IF NOT EXISTS `Portfolio` (
  `cid` int(11) NOT NULL,
  `stock` varchar(5) NOT NULL,
  `shares` int(10) unsigned DEFAULT NULL,
  `purchase_price` double(10,2) DEFAULT NULL,
  PRIMARY KEY (`cid`,`stock`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `Transactions`
--

CREATE TABLE IF NOT EXISTS `Transactions` (
  `id` int(11) NOT NULL,
  `stock` varchar(5) NOT NULL DEFAULT '',
  `shares` int(11) NOT NULL DEFAULT '0',
  `amount` decimal(10,2) NOT NULL,
  `ts` datetime NOT NULL DEFAULT '0000-00-00 00:00:00',
  PRIMARY KEY (`id`,`stock`,`shares`,`ts`,`amount`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
