/*
 * This file is part of EasyRPG Editor.
 *
 * EasyRPG Editor is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * EasyRPG Editor is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with EasyRPG Editor. If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include <QDialog>
#include "model/project.h"

namespace Ui {
class OpenProjectDialog;
}

class OpenProjectDialog : public QDialog
{
	Q_OBJECT

public:
	explicit OpenProjectDialog(QWidget *parent = nullptr);
	~OpenProjectDialog();

	void setDefaultDir(const QString& n_defDir);
	QString getDefaultDir();

	std::shared_ptr<Project> getProject();

private slots:
	void on_toolProjectPath_clicked();

	void on_tableProjects_cellDoubleClicked(int row, int column);

	void on_tableProjects_itemSelectionChanged();

private:
	Ui::OpenProjectDialog *ui;
	QString m_defaultDir;
	bool removeDir(const QString &dirName);
	void refreshProjectList();
	Project::ProjectList prjList;
};

