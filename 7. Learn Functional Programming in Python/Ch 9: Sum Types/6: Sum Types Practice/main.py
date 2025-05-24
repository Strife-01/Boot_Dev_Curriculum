from enum import Enum


class CSVExportStatus(Enum):
    PENDING = 1
    PROCESSING = 2
    SUCCESS = 3
    FAILURE = 4


def get_csv_status(status, data):
    match status:
        case CSVExportStatus.PENDING:
            return "Pending...", list(map(lambda l: list(map(lambda t: str(t), l)), data))
        case CSVExportStatus.PROCESSING:
            return "Processing...", "\n".join(list(map(lambda l: ",".join(list(map(lambda t: str(t), l))),data)))
        case CSVExportStatus.SUCCESS:
            return "Success!", data
        case CSVExportStatus.FAILURE:
            return "Unknown error, retrying...", "\n".join(list(map(lambda l: ",".join(list(map(lambda t: str(t), l))),data)))
        case _:
            raise Exception("Unknown export status")


