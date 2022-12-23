import connexion
import six
from flask import abort, make_response

from swagger_server.models.application import Application  # noqa: E501
from swagger_server import util

storage = list()

def create_application(body):  # noqa: E501
    """Метод создания заявки на издательство

     # noqa: E501

    :param body: 
    :type body: dict | bytes

    :rtype: Application
    """
    if connexion.request.is_json:
        body = Application.from_dict(connexion.request.get_json())  # noqa: E501
        id_app = body.id
        for i in storage:
            if i.id == id_app:
                abort(400)

    storage.append(body)
    return make_response('', 200)


def delete_application_by_id(application_id):  # noqa: E501
    """Метод удаления заявки на издательство по идентификатору

     # noqa: E501

    :param application_id: Идентификатор заявки на издательство
    :type application_id: str

    :rtype: None
    """
    for i in storage:
        if i.id == application_id:
            storage.remove(i)
            return make_response('', 200)

    return abort(404)


def get_all_applications():  # noqa: E501
    """Метод получение всех заявок на издательство

     # noqa: E501


    :rtype: List[Application]
    """

    return make_response(storage, 200)


def get_application_by_id(application_id):  # noqa: E501
    """Метод получение заявки на издательство по идентификатору

     # noqa: E501

    :param application_id: Идентификатор заявки на издательство
    :type application_id: str

    :rtype: Application
    """
    for i in storage:
        if i.id == application_id:
            return i

    return abort(404)


def update_application_by_id(body, application_id):  # noqa: E501
    """Метод обновления заявки на издательство по идентификатору

     # noqa: E501

    :param body: 
    :type body: dict | bytes
    :param application_id: Идентификатор заявки на издательство
    :type application_id: str

    :rtype: None
    """
    all_applications_id = [i.id for i in storage]

    if connexion.request.is_json:
        body = Application.from_dict(connexion.request.get_json())  # noqa: E501
        count = 0
        if application_id not in all_applications_id:
            abort(404)
        if application_id != body.id:
            abort(400)
        for i in storage:
            if i.id == application_id:
                storage[count] = body
                return make_response('', 200)
            count += 1

    return abort(400)
