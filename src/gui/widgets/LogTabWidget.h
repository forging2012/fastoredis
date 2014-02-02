#pragma once

#include <QTabWidget>

#include "common/log_levels.hpp"
#include "global/types.h"

namespace fastoredis
{
    class LogWidget;
    class CommandsWidget;

    class LogTabWidget : public QTabWidget
    {
        Q_OBJECT

    public:
        LogTabWidget(QWidget* parent = 0);

    public Q_SLOTS:
        void addLogMessage(const QString &message, common::logging::LEVEL_LOG level);
        void addCommand(const Command &command);

    protected:
        virtual void changeEvent(QEvent *);

    private:
        void retranslateUi();
        LogWidget *_log;
        CommandsWidget *_commands;
    };
}
