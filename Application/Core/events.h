#ifndef STATICCALCULATION_EVENTS_H
#define STATICCALCULATION_EVENTS_H

enum class Events
{
    None = 0,
    Add,
    Edit,
    Delete,
    Saving,
    SavingConfirmed,
    Loading,
    LoadingConfirmed,
    Exit,
    CreateNewPage,
    CoefficientDatabase_OpenWindow,
    About_OpenWindow,
    NewComponent_OpenWindow,
    Options_OpenWindow
};

#endif  // STATICCALCULATION_EVENTS_H
