#include "state_application.h"

bool State_application::getIs_data_saved() const
{
    return is_data_saved;
}

void State_application::setIs_data_saved(bool value)
{
    is_data_saved = value;
}

std::ostream &operator<<(std::ostream &os, const Panel_dimensions &pd) {
    os << "pd{"<< pd.height<<"," << pd.width<<"}";
    return os;
}
