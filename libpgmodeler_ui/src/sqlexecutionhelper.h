/*
# PostgreSQL Database Modeler (pgModeler)
#
# Copyright 2006-2018 - Raphael Araújo e Silva <raphael@pgmodeler.io>
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation version 3.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# The complete text of GPLv3 is at LICENSE file on source code root directory.
# Also, you can get the complete GNU General Public License at <http://www.gnu.org/licenses/>
*/

/**
\ingroup libpgmodeler_ui
\class SQLExecutionHelper
\brief Implements a command execution helper that permit the execution of SQL commands in a thread
*/

#ifndef SQL_EXECUTION_HELPER_H
#define SQL_EXECUTION_HELPER_H

#include <QObject>
#include "connection.h"

class SQLExecutionHelper : public QObject {
	private:
		Q_OBJECT

		Connection connection;

		QString command;

		bool cancelled;

	public:
		SQLExecutionHelper(void);

		void setConnection(Connection conn);
		void setCommand(const QString &cmd);

	public slots:
		void executeCommand(void);
		void cancelCommand(void);

	signals:
		void s_executionFinished(void);
		void s_executionCancelled(void);
		void s_executionAborted(Exception e);
};

#endif